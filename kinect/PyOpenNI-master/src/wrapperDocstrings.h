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


#ifndef WRAPPER_DOCSTRINGS_H
#define	WRAPPER_DOCSTRINGS_H

//72 ////////////////////////////////////////////////////////////////////////

//Context class documentation
const char* Context_DOC =
    "Represents an OpenNI context object.";

const char* Context_valid_DOC =
    "True if this is a valid Context (has been initialized),\n"
    "False otherwise.";
const char* Context_Init_DOC =
    "Initializates the OpenNI library.\n\n"
    "OpenNI *must* be initializated before any of its features can be used.";
const char* Context_Shutdown_DOC =
    "Destroys this context and all of its nodes and resources.\n\n"
    "Deprecated. This context and his objects will be automatically\n"
    "destroyed when they're deleted or no longer used; it's not recommended\n"
    "to call this method.";
const char* Context_StartGeneratingAll_DOC =
    "Make sure all generators are generating data.";
const char* Context_StopGeneratingAll_DOC =
    "Stop all generators from generating data.";
const char* Context_WaitAnyUpdateAll_DOC =
    "Updates all generators nodes in the context,\n"
    "once any of them have new data.";
const char* Context_WaitAndUpdateAll_DOC =
    "Updates all generators nodes in the context,\n"
    "waiting for all to have new data.";
const char* Context_WaitNoneUpdateAll_DOC =
    "Updates all generator nodes in the context, without any waiting.\n"
    "If a node has new data, it will be updated.";
const char* Context_WaitOneUpdateAll_DOC =
    "Updates all generators nodes in the context,\n"
    "waiting for a specific one to have new data.";
const char* Context_OpenFileRecording_DOC =
    "OpenNI provides great flexibility of recording.\n"
    "You can decide you want to record only the final output, e.g.,\n"
    "just a skeleton in movement; or record both the output skeleton\n"
    "and the depth input; or record only the depth input and then\n"
    "recreate the skeleton at run-time after reading the recorded\n"
    "raw depth data. You can also choose which nodes to record.";



//ProductionNode class documentation
const char* ProductionNode_DOC =
    "Base class for all production nodes.";

const char* ProductionNode_IsCapabilitySupported_DOC =
    "Checks if a production node supports a specific capability.";
const char* ProductionNode_valid_DOC =
    "True if this node is a valid node, False otherwise.\n\n"
    "An invalid node will raise a RuntimeError when trying to use\n"
    "any of its functions.";
const char* ProductionNode_name_DOC =
    "The instance name of this production node.";
const char* ProductionNode_context_DOC =
    "Gets the OpenNI context associated with this production node.";


//Generator class documentation
const char* Generator_DOC =
    "Base class for all generator nodes.\n"
    "(Nodes that generate new data.)";

const char* Generator_WaitAndUpdateData_DOC =
    "Updates the data to the latest available one.\n"
    "If needed, the call will block until new data is available.";
const char* Generator_StartGenerating_DOC =
    "Starts generation of the output.\n"
    "This will also cause all dependencies to start generating.";
const char* Generator_StopGenerating_DOC =
    "Stops generation of the output.";
const char* Generator_generating_DOC =
    "Boolean set to True if this node is generating\n"
    "or to False if it isn't.\n\n"
    "Note that you can also set this property to True or False to\n"
    "start and stop generating, respectively.";
const char* Generator_data_new_DOC =
    "Returns True if the current data is new, False otherwise.\n\n"
    "Meaning, did the data change on the last call to wait_and_update_data(),\n"
    "Context.wait_and_update_all() or Context.wait_one_update_all(...)?";
const char* Generator_timestamp_DOC =
    "The timestamp of current data, in microseconds.";
const char* Generator_frame_id_DOC =
    "The frame ID of current data.";



const char* OpenNIError_DOC =
    "Represents an error in OpenNI.\n"
    "This is thrown by OpenNI when an error occurs.\n\n"
    "You can use this class to get the name of an error code,\n"
    "as well as convert it to a meaningful error string.";
const char* OpenNIError_status_name_DOC =
    "The name of the Xiron Status enumerator, as a string.";
const char* OpenNIError_status_string_DOC =
    "Converts the Xiron Status enumerator into a meaningful error string.";
const char* OpenNIError_status_DOC =
    "The Xiron Status enumerator (error code) of this error.";
const char* OpenNIError__str__DOC =
    "Gets a string representing this error.\n\n"
    "Currently, this just returns the status_string property.";


#endif	/* WRAPPER_DOCSTRINGS_H */
