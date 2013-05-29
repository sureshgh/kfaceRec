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


#ifndef RECORDER_WRAPPER_H
#define	RECORDER_WRAPPER_H

#include "wrapperTypes.h"

void Recorder_Create_wrapped(xn::Recorder& self, xn::Context& ctx);

void Recorder_SetDestination_wrapped(xn::Recorder& self, const std::string& strDest);
std::string Recorder_GetDestination_wrapped(xn::Recorder& self);

void Recorder_AddNodeToRecording_wrapped(xn::Recorder& self, xn::ProductionNode& node);
void Recorder_AddNodeToRecording_WithComp_wrapped(xn::Recorder& self, xn::ProductionNode& node, unsigned int compression);
void Recorder_RemoveNodeFromRecording_wrapped(xn::Recorder& self, xn::ProductionNode& node);

void Recorder_Record_wrapped(xn::Recorder& self);

#endif	/* RECORDER_WRAPPER_H */
