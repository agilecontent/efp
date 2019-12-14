//
// Created by Anders Cedronius on 2019-12-05.
//

#ifndef EFP_UNITTEST3_H
#define EFP_UNITTEST3_H

#include "../ElasticFrameProtocol.h"

#define MTU 1456 //SRT-max

class UnitTest3 {
public:
    bool startUnitTest();
private:
    void sendData(const std::vector<uint8_t> &subPacket);
    void gotData(ElasticFrameProtocol::pFramePtr &packet, ElasticFrameContent content, bool broken, uint64_t pts, uint32_t code, uint8_t stream, uint8_t flags);
    bool waitForCompletion();
    ElasticFrameProtocol *myEFPReciever = nullptr;
    ElasticFrameProtocol *myEFPPacker = nullptr;
    std::atomic_bool unitTestActive;
    std::atomic_bool unitTestFailed;
    int activeUnitTest = 3;
};

#endif //EFP_UNITTEST3_H
