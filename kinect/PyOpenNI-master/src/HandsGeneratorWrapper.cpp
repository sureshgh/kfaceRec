/* ***** BEGIN GPL LICENSE BLOCK *****
 *
 * This file is part of PyOpenNI.
 *
 * PyOpenNI is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * PyOpenNI is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with PyOpenNI.  If not, see <http://www.gnu.org/licenses/>.
 *
 * PyOpenNI is Copyright (C) 2011, Xavier Mendez (jmendeth).
 * OpenNI Python Wrapper (ONIPY) is Copyright (C) 2011, Gabriele Nataneli (gamix).
 *
 * ***** END GPL LICENSE BLOCK ***** */


#include "HandsGeneratorWrapper.h"

#include "wrapperTypes.h"
#include "wrapperExceptions.h"
#include "conversionHelpers.h"

void HandsGenerator_Create_wrapped(xn::HandsGenerator& self, xn::Context& ctx) {
    check( self.Create(ctx, NULL, NULL) );
}

XnCallbackHandle HandsGenerator_RegisterHandCallbacks_wrapped(xn::HandsGenerator& self, BP::object create, BP::object update, BP::object destroy) {
    checkValid(self);
    
    XnCallbackHandle handle;
    
    BP::object* cookie = new BP::object [3]; //FIXME: fix cookie
    
    cookie[0] = create;
    cookie[1] = update;
    cookie[2] = destroy;
    
    check( self.RegisterHandCallbacks(&Create_callback, &Update_callback, &Destroy_callback, cookie, handle) );
    
    return handle;
}

void HandsGenerator_StartTracking_wrapped(xn::HandsGenerator& self, BP::list point) {
    check( self.StartTracking(convertToVec3D((boost::python::list) point)) );
}

/** Internal callback implementations **/
void XN_CALLBACK_TYPE Create_callback(xn::HandsGenerator& src, XnUserID user, const XnPoint3D *pPosition, XnFloat fTime, void* cookie) {
    BP::object& func = ((BP::object*)cookie)[0];
    
    //Call the function
    func(src, user, convertVec3D(*pPosition), fTime);
}

void XN_CALLBACK_TYPE Update_callback(xn::HandsGenerator& src, XnUserID user, const XnPoint3D *pPosition, XnFloat fTime, void* cookie) {
    BP::object& func = ((BP::object*)cookie)[1];
    
    //Call the function
    func(src, user, convertVec3D(*pPosition), fTime);
}

void XN_CALLBACK_TYPE Destroy_callback(xn::HandsGenerator& src, XnUserID user, XnFloat fTime, void* cookie) {
    BP::object& func = ((BP::object*)cookie)[2];
    
    //Call the function
    func(src, user, fTime);
}