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

#include "IRGeneratorWrapper.h"

#include "wrapperTypes.h"
#include "wrapperExceptions.h"
#include "conversionHelpers.h"
#include "util/PythonOutputStream.h"
#include "IRMapWrapper.h"

using namespace pyopenni;

xn::IRMetaData* IRGenerator_GetMetaData_wrapped(xn::IRGenerator const & self) {
    checkValid(self);

    xn::IRMetaData * ret = new xn::IRMetaData;
    self.GetMetaData(*ret);
    return ret;
}

BP::tuple IRGenerator_GetIRMapTuple_wrapped(xn::IRGenerator const & self) {
    checkValid(self);

#ifdef _DEBUG
    if (IsDataNew() == false)
        PyCout << "WARNING: data is out of sync!" << std::endl;
#endif

    xn::IRMetaData metadata;
    self.GetMetaData(metadata);

    XnIRPixel const* irMap = self.GetIRMap();

    BP::tuple mapTuple;
    convert(mapTuple, irMap, metadata.XRes(), metadata.YRes());

    return mapTuple;

}

void IRGenerator_Create_wrapped(xn::IRGenerator& self, xn::Context& ctx) {
    check( self.Create(ctx, NULL, NULL) );
}

IRMap IRGenerator_GetWrappedMap(xn::IRGenerator& self) {
    checkValid(self);
    
    xn::IRMetaData metadata;
    self.GetMetaData(metadata);
    
    XnUInt32XYPair size;
    size.X = metadata.XRes();
    size.Y = metadata.YRes();
    
    return IRMap(self.GetIRMap(), size);
}