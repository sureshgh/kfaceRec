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


#include "PlayerWrapper.h"

#include "wrapperTypes.h"
#include "wrapperExceptions.h"


void Player_Create_wrapped(xn::Player& self, xn::Context& ctx) {
    check( self.Create(ctx, "oni") );
}

void Player_SetRepeat(xn::Player& self, XnBool bRepeat) {
    checkValid(self);  

    check( self.SetRepeat(bRepeat) );
}

void Player_ReadNext(xn::Player& self) {
    checkValid(self);  

    check( self.ReadNext() );
}

XnBool Player_IsEOF(xn::Player& self) {
    checkValid(self);  

    return self.IsEOF();
}

void Player_SetSource(xn::Player& self, const std::string &sourceFile) {
    checkValid(self);  

    check( self.SetSource(XN_RECORD_MEDIUM_FILE, sourceFile.c_str()) );
}

std::string Player_GetSource(xn::Player& self) {
    checkValid(self);  

    XnUInt32 nBufSize = 1024;
    XnChar buf[1024];
    XnRecordMedium * medium = new XnRecordMedium;
    check( self.GetSource(*medium, (XnChar*)(&buf), nBufSize) );
    delete medium;
    return std::string(buf);
}

XnDouble Player_GetPlaybackSpeed(xn::Player& self) {
    checkValid(self);  

    return self.GetPlaybackSpeed();
}


void Player_SetPlaybackSpeed(xn::Player& self, XnDouble dSpeed) {
    checkValid(self);  

    check( self.SetPlaybackSpeed(dSpeed) );
}


