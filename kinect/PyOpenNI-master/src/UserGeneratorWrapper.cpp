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

#include "UserGeneratorWrapper.h"

#include "wrapperTypes.h"
#include "wrapperExceptions.h"
#include "conversionHelpers.h"

void UserGenerator_Create_wrapped(xn::UserGenerator& self, xn::Context& ctx) {
    check( self.Create(ctx, NULL, NULL) );
}

XnUInt16 UserGenerator_CountUsers(xn::UserGenerator const & self) {
    checkValid(self);

    return self.GetNumberOfUsers();
}

BP::list UserGenerator_GetUsers_wrapped(xn::UserGenerator& self) {
    checkValid(self);

    XnUInt16 users = self.GetNumberOfUsers();
    BP::list ret;

    if (users > 0) {
        std::vector<XnUserID> result (users);
    
        check( self.GetUsers((XnUserID*)result.data(), users) );
    
        for (XnUInt16 i = 0; i < users; i++) {
            ret.append(result.at(i));
        }
    }
    return ret;
}

xn::SkeletonCapability UserGenerator_GetSkeletonCap_wrapped(xn::UserGenerator& self) {
    checkValid(self);
    
    if (!self.IsCapabilitySupported(XN_CAPABILITY_SKELETON)) {
        return NULL;
    }
    
    return self.GetSkeletonCap();
}

xn::PoseDetectionCapability UserGenerator_GetPoseDetectionCap_wrapped(xn::UserGenerator& self) {
    checkValid(self);
    
    if (!self.IsCapabilitySupported(XN_CAPABILITY_POSE_DETECTION)) {
        return NULL;
    }
    
    return self.GetPoseDetectionCap();
}

BP::list UserGenerator_GetCoM_wrapped(xn::UserGenerator& self, XnUserID user) {
    checkValid(self);
    
    XnPoint3D ret;
    check( self.GetCoM(user,ret) );
    return convertVec3D(ret);
}

BP::tuple UserGenerator_GetUserPixels_wrapped(xn::UserGenerator& self, XnUserID user) {
    checkValid(self);

    xn::SceneMetaData * metadata = new xn::SceneMetaData;
    self.GetUserPixels(user, *metadata);

    XnLabel const* sceneMap = metadata->Data();

    BP::tuple mapTuple;
    convert(mapTuple, sceneMap, metadata->XRes(), metadata->YRes());

    return mapTuple;
}

XnCallbackHandle UserGenerator_RegisterUserCallbacks_wrapped(xn::UserGenerator& self, BP::object newUser, BP::object lostUser) {
    checkValid(self);
    
    XnCallbackHandle handle;
    
    BP::object* cookie = new BP::object [2]; //FIXME: fix cookie
    
    cookie[0] = newUser;
    cookie[1] = lostUser;
    
    check( self.RegisterUserCallbacks(&NewUser_callback, &LostUser_callback, cookie, handle) );
    
    return handle;
}

void UserGenerator_UnregisterUserCallbacks_wrapped(xn::UserGenerator& self, XnCallbackHandle handle) {
    checkValid(self);
    
    self.UnregisterUserCallbacks(handle);
}

/** Internal callback implementations **/
void XN_CALLBACK_TYPE NewUser_callback(xn::UserGenerator& src, XnUserID user, void* cookie) {
    BP::object& func = ((BP::object*)cookie)[0];
    
    //Call the function
    func(src, user);
}
void XN_CALLBACK_TYPE LostUser_callback(xn::UserGenerator& src, XnUserID user, void* cookie) {
    BP::object& func = ((BP::object*)cookie)[1];
    
    //Call the function
    func(src, user);
}
