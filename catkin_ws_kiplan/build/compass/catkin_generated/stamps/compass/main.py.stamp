#!/usr/bin/env python
import rospy
import serial
from utils.msg import compass

ser = serial.Serial('/dev/ttyCCM0', 57600, timeout=0, parity=serial.PARITY_EVEN, rtscts=1)

def talker():
    print("test")
    pub = rospy.Publisher('chattercompass', compass, queue_size=10)
    rospy.init_node('main', anonymous=True)
    rate = rospy.Rate(10) # 10hz
    while not rospy.is_shutdown():
        comps = compass()

        cc=str(ser.read())
        if(len(cc) <= 0): continue

        # ss = cc.split('=')



        # yaw = cc[3:cc.index(',')]

        print(cc)


        # comps.x = float(yaw)
        # pub.publish(comps)

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass
