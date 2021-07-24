#include <ControllerG.h>
#include <pluginlib/class_list_macros.h>


namespace controllerg
{


    void ControllerG::onInit() {
        ros::NodeHandle nh("~");
        
        ros::Time::waitForValid();

        mrs_lib::ParamLoader param_loader(nh, "ControllerG");

        param_loader.loadParam("uav_name", _uav_name_);

        if (!param_loader.loadedSuccessfully()) {
            ROS_ERROR("[WaypointFlier]: failed to load non-optional parameters!");
            ros::shutdown();
        }

        get_stance = nh.advertiseService("/" + _uav_name_ + "/control_manager/controller_gripper", &ControllerG::GetStance, this);

        pub_open_R = nh.advertise<std_msgs::Float64>("/" + _uav_name_ + "/gripper_mecha_right_joint_controller/command", 5);
        pub_open_L = nh.advertise<std_msgs::Float64>("/" + _uav_name_ + "/gripper_mecha_left_joint_controller/command", 5);
        pub_close_R = nh.advertise<std_msgs::Float64>("/" + _uav_name_ + "/gripper_mecha_right_joint_controller/command", 5);
        pub_close_L = nh.advertise<std_msgs::Float64>("/" + _uav_name_ + "/gripper_mecha_left_joint_controller/command", 5);
        pub_down = nh.advertise<std_msgs::Float64>("/" + _uav_name_ + "/gripper_mecha_mount_stretcher_joint_controller/command", 5);
        pub_up = nh.advertise<std_msgs::Float64>("/" + _uav_name_ + "/gripper_mecha_mount_stretcher_joint_controller/command", 5);
        
        ROS_INFO_ONCE("[CONTROLLERG]: initialized");
        ROS_INFO_ONCE("[CONTROLLERG]: service is available");

        ros::spin();
    }

    bool ControllerG::GetStance(controller_g_msgs::GetStanceRequest& req,
                                controller_g_msgs::GetStanceResponse& res) {
        ROS_INFO("Service called for %s the gripper", req.stance.c_str());

        /* Function to publisher joints pose based in stance */ 

        std::string stance_req = req.stance;
        ROS_INFO("stance: %s", req.stance.c_str());

        if(stance_req == "open"){
            
            /* move the right claw for a open stance */
            std_msgs::Float64 value_open_R;
            value_open_R.data = 0.8;
            pub_open_R.publish(value_open_R);

            /* move the left claw for a open stance */
            std_msgs::Float64 value_open_L;
            value_open_L.data = -0.8;
            pub_open_L.publish(value_open_L);
            
            ROS_INFO("requesting the gripper to %s", req.stance.c_str());
            
        }
        if (stance_req == "close"){

            /* move the right claw for a close stance */
            std_msgs::Float64 value_close_R;
            value_close_R.data = 0.0;
            pub_close_R.publish(value_close_R);

            /* move the left claw for a close stance */
            std_msgs::Float64 value_close_L;
            value_close_L.data = 0.0;
            pub_close_L.publish(value_close_L);

            ROS_INFO("requesting the gripper to %s", req.stance.c_str());

        }
        if (stance_req == "up"){

            /* move the stretcher claw for a up stance */
            std_msgs::Float64 value_up;
            value_up.data = 0.0;
            pub_up.publish(value_up);

            ROS_INFO("requesting the gripper to %s", req.stance.c_str());

        }
        if (stance_req == "down"){

            /* move the stretcher claw for a down stance */
            std_msgs::Float64 value_down;
            value_down.data = 1.56;
            pub_down.publish(value_down);

            ROS_INFO("requesting the gripper to %s", req.stance.c_str());
        }                
        if (stance_req != "close" && stance_req != "open" && stance_req != "down" && stance_req != "up"){
            ROS_ERROR("The stance %s not correct", req.stance.c_str());
        }

        return true;
    }

} //namespace controller_g
PLUGINLIB_EXPORT_CLASS(controllerg::ControllerG, nodelet::Nodelet);