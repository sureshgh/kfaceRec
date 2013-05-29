#!/usr/bin/python
## The equivalent of:
##  "Working with the Skeleton"
## in the OpenNI user guide.

"""
This shows how to identify when a new user is detected, look for a pose for
that user, calibrate the users when they are in the pose, and track them.

Specifically, it prints out the location of the users' head,
as they are tracked.
"""

# Pose to use to calibrate the user
pose_to_use = 'Psi'

import cv
from openni import *

ctx = Context()
ctx.init()

newImg = cv.LoadImage("dark.jpg")
#cv.NamedWindow("Main", cv.CV_WINDOW_AUTOSIZE)
cv.ShowImage("Main",newImg)

# Create the user generator
user = UserGenerator()
user.create(ctx)

# Obtain the skeleton & pose detection capabilities
skel_cap = user.skeleton_cap
pose_cap = user.pose_detection_cap

# Declare the callbacks
def new_user(src, id):
    print "1/4 User {} detected. Looking for pose..." .format(id)
    pose_cap.start_detection(pose_to_use, id)

def pose_detected(src, pose, id):
    print "2/4 Detected pose {} on user {}. Requesting calibration..." .format(pose,id)
    pose_cap.stop_detection(id)
    skel_cap.request_calibration(id, True)

def calibration_start(src, id):
    print "3/4 Calibration started for user {}." .format(id)

def calibration_complete(src, id, status):
    if status == CALIBRATION_STATUS_OK:
        print "4/4 User {} calibrated successfully! Starting to track." .format(id)
        skel_cap.start_tracking(id)
    else:
        print "ERR User {} failed to calibrate. Restarting process." .format(id)
        new_user(user, id)

def lost_user(src, id):
    print "--- User {} lost." .format(id)

# Register them
user.register_user_cb(new_user, lost_user)
pose_cap.register_pose_detected_cb(pose_detected)
skel_cap.register_c_start_cb(calibration_start)
skel_cap.register_c_complete_cb(calibration_complete)

# Set the profile
skel_cap.set_profile(SKEL_PROFILE_ALL)

# Start generating
ctx.start_generating_all()
print "0/4 Starting to detect users. Press Ctrl-C to exit."

while True:
    # Update to next frame
    ctx.wait_and_update_all()

    # Extract head position of each tracked user
    for id in user.users:
        if skel_cap.is_tracking(id):
            newImg = cv.LoadImage("dark.jpg")
            head = skel_cap.get_joint_position(id, SKEL_HEAD)
            #print "  {}: head at ({loc[0]}, {loc[1]}, {loc[2]}) [{conf}]" .format(id, loc=head.point, conf=head.confidence)
            neck = skel_cap.get_joint_position(id, SKEL_NECK)
            #print "  {}: neck at ({loc[0]}, {loc[1]}, {loc[2]}) [{conf}]" .format(id, loc=neck.point, conf=neck.confidence)
            lHand = skel_cap.get_joint_position(id, SKEL_LEFT_HAND)
            #print "  {}: LHand at ({loc[0]}, {loc[1]}, {loc[2]}) [{conf}]" .format(id, loc=lHand.point, conf=lHand.confidence)
            rHand = skel_cap.get_joint_position(id, SKEL_RIGHT_HAND)
            #print "  {}: RHand at ({loc[0]}, {loc[1]}, {loc[2]}) [{conf}]" .format(id, loc=rHand.point, conf=rHand.confidence)
            lElbow = skel_cap.get_joint_position(id, SKEL_LEFT_ELBOW)
            #print "  {}: LElbow at ({loc[0]}, {loc[1]}, {loc[2]}) [{conf}]" .format(id, loc=lElbow.point, conf=lElbow.confidence)
            rElbow = skel_cap.get_joint_position(id, SKEL_RIGHT_ELBOW)
            torso = skel_cap.get_joint_position(id, SKEL_TORSO)
            lHip = skel_cap.get_joint_position(id, SKEL_LEFT_HIP)
            rHip = skel_cap.get_joint_position(id, SKEL_RIGHT_HIP)
            #print "  {}: RElbow at ({loc[0]}, {loc[1]}, {loc[2]}) [{conf}]" .format(id, loc=rElbow.point, conf=rElbow.confidence)
            cv.Circle(newImg, (640-int(head.point[0]),240-int(head.point[1])),2,cv.RGB(17, 110, 255))
            cv.Circle(newImg, (640-int(neck.point[0]),240-int(neck.point[1])),2,cv.RGB(17, 110, 255))
            cv.Circle(newImg, (640-int(lHand.point[0]),240-int(lHand.point[1])),2,cv.RGB(17, 110, 255))
            cv.Circle(newImg, (640-int(rHand.point[0]),240-int(rHand.point[1])),2,cv.RGB(17, 110, 255))
            cv.Circle(newImg, (640-int(lElbow.point[0]),240-int(lElbow.point[1])),2,cv.RGB(17, 110, 255))
            cv.Circle(newImg, (640-int(rElbow.point[0]),240-int(rElbow.point[1])),2,cv.RGB(17, 110, 255))
            cv.Circle(newImg, (640-int(torso.point[0]),240-int(torso.point[1])),2,cv.RGB(17, 110, 255))
            cv.Circle(newImg, (640-int(torso.point[0]),240-int(lHip.point[1])),2,cv.RGB(17, 110, 255))
            cv.Circle(newImg, (640-int(torso.point[0]),240-int(rHip.point[1])),2,cv.RGB(17, 110, 255))
            #cv.SaveImage("murkha.png",newImg)
            #cv.Flip(newImg,None,1)
            cv.ShowImage("Main",newImg)
            cv.WaitKey(10)
            #exit()

