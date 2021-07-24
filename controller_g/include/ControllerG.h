#pragma once
#ifndef CONTROLLERG_H
#define CONTROLLERG_H

#include <string>
#include <map>

#include <ros/ros.h>
#include <ros/package.h>
#include <std_msgs/Float64.h>
#include <nodelet/nodelet.h>
#include "controller_g_msgs/GetStance.h"
#include <mrs_lib/param_loader.h>

namespace controllerg
{
    struct msgs
    {
        std::string stance;
    };

    class ControllerG : public nodelet::Nodelet {
        public:
            virtual void onInit();
        private:
            /* flags */
            bool is_initialized_ = false;
            
            /*ros parameters */
            std::string _uav_name_;
        
  // | ---------------- service server callbacks ---------------- |

            bool GetStance(controller_g_msgs::GetStanceRequest& req, controller_g_msgs::GetStanceResponse& res);
            ros::ServiceServer get_stance;

  // | --------------------- timer callbacks -------------------- |

        ros::Publisher pub_open_R;
        ros::Publisher pub_open_L;
        ros::Publisher pub_close_R;
        ros::Publisher pub_close_L;
        ros::Publisher pub_down;
        ros::Publisher pub_up;

    };
    //}
} // namespace controller_g
#endif