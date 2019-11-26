/**
* @file data_recv.cpp
*
* Copyright (C) 2018. Huawei Technologies Co., Ltd. All rights reserved.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>
#include "inc/data_recv.h"
#include "inc/error_code.h"
#include "inc/common.h"
#include "inc/util.h"
/**
* @ingroup DetectionSSDDataRecvInterface
* @brief RecvData RecvData callback,Save the file
* @param [in]
*/
HIAI_StatusT DetectionSSDDataRecvInterface::RecvData
    (const std::shared_ptr<void>& message)
{
    std::shared_ptr<std::string> data =
        std::static_pointer_cast<std::string>(message);
    if (nullptr == data)
    {
        HIAI_ENGINE_LOG("Fail to receive data");
        return HIAI_INVALID_INPUT_MSG;
    }

    Util::SSDDump(file_name_, data);
    return HIAI_OK;
}
