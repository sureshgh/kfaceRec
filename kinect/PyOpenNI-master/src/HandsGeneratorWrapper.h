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


#ifndef HANDS_GENERATOR_WRAPPER_H
#define	HANDS_GENERATOR_WRAPPER_H

#include "wrapperTypes.h"

void HandsGenerator_Create_wrapped(xn::HandsGenerator& self, xn::Context& ctx);

XnCallbackHandle HandsGenerator_RegisterHandCallbacks_wrapped(xn::HandsGenerator& self, BP::object create, BP::object update, BP::object destroy);

void HandsGenerator_StartTracking_wrapped(xn::HandsGenerator& self, BP::list point);

/** Internal callback implementations **/
void Create_callback(xn::HandsGenerator& src, XnUserID user, const XnPoint3D *pPosition, XnFloat fTime, void* cookie);
void Update_callback(xn::HandsGenerator& src, XnUserID user, const XnPoint3D *pPosition, XnFloat fTime, void* cookie);
void Destroy_callback(xn::HandsGenerator& src, XnUserID user, XnFloat fTime, void* cookie);

#endif	/* HANDS_GENERATOR_WRAPPER_H */
