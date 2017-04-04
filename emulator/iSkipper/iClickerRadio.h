#ifndef I_CLICKER_RADIO_H
#define I_CLICKER_RADIO_H

#include <Arduino.h>
#include "iClickerRadioIncludes.h"


// threshold for triggerins fifo transmit interrupt
#define RF_FIFOTHRESH_TXSTART_FIFOTHRESH_IC 0x04


//RegSyncValue1-8 for sending is:
// 0x85, 0x85, 0x85, 0, 0...

//RegSyncValue1-8 for recving is:
// encoded_id[0], encoded_id[1], encoded_id[2], 0, 0...

// Note: sending packets are 5 bytes
//  Recieving packets from base are 7 bytes




class iClickerRadio : public RFM69
{
public:


    iClickerRadio(uint8_t slaveSelectPin=RF69_SPI_CS, uint8_t interruptPin=RF69_IRQ_PIN, bool isRFM69HW=false, uint8_t interruptNum=RF69_IRQ_NUM);

    virtual bool initialize();

    // set the frequency (in Hz)
    void setChannel(iClickerChannel_t chan);

    void setChannelType(iClickerChannelType_t chanType);



protected:

    iClickerChannel_t _chan; //which channel AA?
    iClickerChannelType_t _chanType; //send or recv channel?

};

#endif
