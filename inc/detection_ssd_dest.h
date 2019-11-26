/**
* @file detection_ssd_dest.h
*
* Copyright (C) 2018. Huawei Technologies Co., Ltd. All rights reserved.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#ifndef INC_DETECTION_SSD_DEST_H_
#define INC_DETECTION_SSD_DEST_H_
#include <hiaiengine/api.h>
#include <hiaiengine/multitype_queue.h>
#include "inc/common.h"

/*
* Dest Engine
*/
class DestEngine : public hiai::Engine
{
 public:
    DestEngine() :
        input_que_(DEST_ENGINE_INPUT_SIZE) {}
    /**
    * @ingroup SourceEngine
    * @brief SourceEngine Process function
    * @param [in]: DEST_ENGINE_INPUT_SIZE, Source Engine in port
    * @param [in]: DEST_ENGINE_OUTPUT_SIZE, Source Engine out port
    * @param [out]: HIAI_StatusT
    */
    HIAI_DEFINE_PROCESS(DEST_ENGINE_INPUT_SIZE, DEST_ENGINE_OUTPUT_SIZE)

 private:
    hiai::MultiTypeQueue input_que_;
};
#endif  // INC_DETECTION_SSD_DEST_H_
