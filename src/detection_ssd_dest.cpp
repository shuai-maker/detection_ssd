/**
* @file detection_ssd_dest.cpp
*
* Copyright (C) 2018. Huawei Technologies Co., Ltd. All rights reserved.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#include <unistd.h>
#include <thread>
#include <hiaiengine/data_type.h>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <string>
#include "inc/detection_ssd_dest.h"
#include "inc/common.h"
#include "inc/util.h"
#include "inc/error_code.h"

/**
* @ingroup DestEngine
* @brief DestEngine Process function
* @param [in]:arg0
*/
HIAI_IMPL_ENGINE_PROCESS("DestEngine", DestEngine, DEST_ENGINE_INPUT_SIZE)
{
    HIAI_ENGINE_LOG(this, HIAI_OK, "DestEngine Process");
    input_que_.PushData(0, arg0);
    input_que_.PushData(1, arg1);
    std::shared_ptr<std::string> data_bbox_ptr =
        std::static_pointer_cast<std::string>(arg0);
    std::shared_ptr<std::string> data_num_ptr =
        std::static_pointer_cast<std::string>(arg1);

    // Obtain data from the queue. If no two parameters are received, wait.
    if (!input_que_.PopAllData(data_bbox_ptr, data_num_ptr))
    {
        HIAI_ENGINE_LOG("fail to get all  message");
        return HIAI_INVALID_INPUT_MSG;
    }

    // Send data_num and data_bbox to the callback function.
    hiai::Engine::SendData(0, "string",
        std::static_pointer_cast<void>(data_bbox_ptr));
    hiai::Engine::SendData(1, "string",
        std::static_pointer_cast<void>(data_num_ptr));
    HIAI_ENGINE_LOG(this, HIAI_OK, "DestEngine Process Success");
    return HIAI_OK;
}
