/**
* @file data_recv.h
*
* Copyright (C) 2018. Huawei Technologies Co., Ltd. All rights reserved.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#ifndef INC_DATA_RECV_H_
#define INC_DATA_RECV_H_
#include <hiaiengine/api.h>
#include <string>
class DetectionSSDDataRecvInterface : public hiai::DataRecvInterface
{
 public:
    /**
    * @ingroup DetectionSSDDataRecvInterface
    * @brief Construct Function
    * @param [in]desc:std::string
    */
    DetectionSSDDataRecvInterface(const std::string& filename) :
        file_name_(filename) {}

    /**
    * @ingroup DetectionSSDDataRecvInterface
    * @brief RecvData RecvData callback,Save the File
    * @param [in]
    */
    HIAI_StatusT RecvData(const std::shared_ptr<void>& message);

 private:
    std::string file_name_;     // Target Save File
};
#endif  // INC_DATA_RECV_H_
