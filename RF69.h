#ifndef RF69_h
#define RF69_h

namespace RF69 {
    extern uint32_t frf;
    extern uint8_t  group;
    extern uint8_t  node;
    extern uint8_t  rssi;
    extern uint8_t  rssiAbort;
    extern uint8_t  rssiEndRX;
    extern uint8_t  rssiEndTX;
    extern int16_t  afc;
    extern int16_t  fei;
    extern uint8_t  lna;
    extern uint16_t interruptCount;
    extern uint16_t rxP;
    extern uint16_t txP;
    extern uint16_t discards;
    extern uint16_t unexpected;
    extern uint8_t  unexpectedFSM;
    extern uint8_t  unexpectedIRQFLAGS2;
    extern uint16_t byteCount;
    extern uint16_t underrun;
    extern uint8_t  present;
    extern uint16_t pcIntCount;
    extern uint8_t  pcIntBits;
    extern int8_t   payloadLen;
    extern uint16_t badLen;
    extern uint16_t packetShort;
    extern uint16_t nestedInterrupts;
    extern uint8_t  IRQFLAGS2;
    extern uint8_t  DIOMAPPING1;
    
    void setFrequency (uint32_t freq);
    bool canSend ();
    bool sending ();
    void sleep (bool off);
    uint8_t control(uint8_t cmd, uint8_t val);
    int8_t readTemperature(int8_t);
    uint8_t* SPI_pins();  // {OPTIMIZE_SPI, PINCHG_IRQ, RF69_COMPAT, RFM_IRQ, 
                          //  SPI_SS, SPI_MOSI, SPI_MISO, SPI_SCK }
    
    void configure_compat ();
    uint16_t recvDone_compat (uint8_t* buf);
/// Call this to skip transmission of specific bytes in rf12_buf
/// Default value 2 skips the Jeelib header enabling non-Jeelib FSK packets 
    void skip_hdr (uint8_t skip=2);
    void sendStart_compat (uint8_t hdr, const void* ptr, uint8_t len);
    void interrupt_compat();
}

#endif
