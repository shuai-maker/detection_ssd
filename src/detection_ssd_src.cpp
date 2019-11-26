/**
* @file detection_ssd_src.cpp
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
#include "inc/detection_ssd_src.h"
#include "inc/common.h"
#include "inc/util.h"
#include "inc/error_code.h"


void deleteMemoryNew(void* ptr)
{
    if(ptr != nullptr) {
        delete[] reinterpret_cast<char*>(ptr);
    }
}

/**
* @ingroup SourceEngine
* @brief SourceEngine Process function
* @param [in]:arg0
*/
HIAI_IMPL_ENGINE_PROCESS("SourceEngine", SourceEngine, SOURCE_ENGINE_INPUT_SIZE)
{
    HIAI_ENGINE_LOG(this, HIAI_OK, "SourceEngine Process");
    std::cout<<"SourceEngine Process Start"<<std::endl;
    // Obtain the path of the original file.
    std::shared_ptr<std::string> input_arg =
        std::static_pointer_cast<std::string>(arg0);
    if (nullptr == input_arg)
    {
        HIAI_ENGINE_LOG(this, HIAI_INVALID_INPUT_MSG,
            "fail to process invalid message");
        return HIAI_INVALID_INPUT_MSG;
    }

    // Reads data and generates information.
    uint32_t bufSize = 0;

    char* bufData = Util::ReadBinFile(input_arg, &bufSize);

    std::shared_ptr<hiai::RawDataBuffer> raw_data_ptr =
        std::make_shared<hiai::RawDataBuffer>();
    raw_data_ptr->len_of_byte = bufSize;
    raw_data_ptr->data.reset((unsigned char*)bufData, deleteMemoryNew);
    std::cout<<"SourceEngine, ReadBinFile, len_of_byte = "<<raw_data_ptr->len_of_byte<<std::endl;
    // Transferred to DetectionSSD Engine
    hiai::Engine::SendData(0, "RawDataBuffer",
        std::static_pointer_cast<void>(raw_data_ptr));

    HIAI_ENGINE_LOG(this, HIAI_OK, "SourceEngine Process Success");
    std::cout<<"SourceEngine Process Success"<<std::endl;

    return HIAI_OK;
}
