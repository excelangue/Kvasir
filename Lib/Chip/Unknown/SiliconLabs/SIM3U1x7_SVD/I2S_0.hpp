#pragma once 
#include "Register/Utility.hpp"
namespace Kvasir {
//None
    namespace Nonetxcontrol{    ///<Transmit Control
        using Addr = Register::Address<0x4003a000,0xd88c001c,0,unsigned>;
        ///DFS Generator Enable. 
        enum class fsgenVal {
            disabled=0x00000000,     ///<Disable the internal DFS generator.
            enabled=0x00000001,     ///<Enable the internal DFS generator.
        };
        namespace fsgenValC{
            constexpr MPL::Value<fsgenVal,fsgenVal::disabled> disabled{};
            constexpr MPL::Value<fsgenVal,fsgenVal::enabled> enabled{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,fsgenVal> fsgen{}; 
        ///DFS Synchronize Enable. 
        enum class fssenVal {
            disabled=0x00000000,     ///<The internal DFS generator starts immediately when FSGEN is set to 1.
            enabled=0x00000001,     ///<Synchronize the rising edge of the internally generated WS signal from the DFS generator to the rising edge of the external WS input signal.
        };
        namespace fssenValC{
            constexpr MPL::Value<fssenVal,fssenVal::disabled> disabled{};
            constexpr MPL::Value<fssenVal,fssenVal::enabled> enabled{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,fssenVal> fssen{}; 
        ///Transmit Delay Disable. 
        enum class ddisVal {
            inactive=0x00000000,     ///<The first data bit is sent on the second or later rising edge of SCK after WS changes.
            active=0x00000001,     ///<The first data bit is sent on the first rising edge of SCK after WS changes.
        };
        namespace ddisValC{
            constexpr MPL::Value<ddisVal,ddisVal::inactive> inactive{};
            constexpr MPL::Value<ddisVal,ddisVal::active> active{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(5,5),Register::ReadWriteAccess,ddisVal> ddis{}; 
        ///Transmit Initial Phase Delay. 
        constexpr Register::BitLocation<Addr,Register::maskFromRange(13,6),Register::ReadWriteAccess,unsigned> fsdel{}; 
        ///Transmit Frame Sync Source Select. 
        enum class fssrcselVal {
            fsinExt=0x00000000,     ///<The word select or frame sync is input from the WS pin.
            fsinInt=0x00000001,     ///<The word select or frame sync is input from the internal DFS generator.
        };
        namespace fssrcselValC{
            constexpr MPL::Value<fssrcselVal,fssrcselVal::fsinExt> fsinExt{};
            constexpr MPL::Value<fssrcselVal,fssrcselVal::fsinInt> fsinInt{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(14,14),Register::ReadWriteAccess,fssrcselVal> fssrcsel{}; 
        ///Transmit Data Fill Select. 
        enum class fillselVal {
            zeros=0x00000000,     ///<Send zeros during unused bit cycles.
            ones=0x00000001,     ///<Send ones during unused bit cycles.
            sign=0x00000002,     ///<Send the sign bit of the current sample (MSB-first format) or last sample (LSB-first format) during unused bit cycles.
            random=0x00000003,     ///<Send pseudo-random data generated by an 8-bit LFSR during unused bit cycles.
        };
        namespace fillselValC{
            constexpr MPL::Value<fillselVal,fillselVal::zeros> zeros{};
            constexpr MPL::Value<fillselVal,fillselVal::ones> ones{};
            constexpr MPL::Value<fillselVal,fillselVal::sign> sign{};
            constexpr MPL::Value<fillselVal,fillselVal::random> random{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(16,15),Register::ReadWriteAccess,fillselVal> fillsel{}; 
        ///Transmit Data Justification Select. 
        enum class jselVal {
            left=0x00000000,     ///<Use left-justified or I2S-style formats.
            right=0x00000001,     ///<Use right-justified format.
        };
        namespace jselValC{
            constexpr MPL::Value<jselVal,jselVal::left> left{};
            constexpr MPL::Value<jselVal,jselVal::right> right{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(17,17),Register::ReadWriteAccess,jselVal> jsel{}; 
        ///Transmit WS Inversion Enable. 
        enum class fsinvenVal {
            disabled=0x00000000,     ///<Don't invert the WS signal. Use this setting for I2S format.
            enabled=0x00000001,     ///<Invert the WS signal.
        };
        namespace fsinvenValC{
            constexpr MPL::Value<fsinvenVal,fsinvenVal::disabled> disabled{};
            constexpr MPL::Value<fsinvenVal,fsinvenVal::enabled> enabled{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(20,20),Register::ReadWriteAccess,fsinvenVal> fsinven{}; 
        ///Transmit SCK Inversion Enable. 
        enum class sclkinvenVal {
            disabled=0x00000000,     ///<Do not invert the transmitter bit clock.
            enabled=0x00000001,     ///<Invert the transmitter bit clock.
        };
        namespace sclkinvenValC{
            constexpr MPL::Value<sclkinvenVal,sclkinvenVal::disabled> disabled{};
            constexpr MPL::Value<sclkinvenVal,sclkinvenVal::enabled> enabled{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(21,21),Register::ReadWriteAccess,sclkinvenVal> sclkinven{}; 
        ///Transmit Order. 
        enum class orderVal {
            leftRight=0x00000000,     ///<Left sample transmitted first, right sample transmitted second. Use this setting for I2S format.
            rightLeft=0x00000001,     ///<Right sample transmitted first, left sample transmitted second.
        };
        namespace orderValC{
            constexpr MPL::Value<orderVal,orderVal::leftRight> leftRight{};
            constexpr MPL::Value<orderVal,orderVal::rightLeft> rightLeft{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(22,22),Register::ReadWriteAccess,orderVal> order{}; 
        ///Transmit Mono Bit-Width Select. 
        enum class mbselVal {
            v8bits=0x00000000,     ///<8 bits are sent per mono sample.
            v9bits=0x00000001,     ///<9 bits are sent per mono sample.
            v16bits=0x00000002,     ///<16 bits are sent per mono sample.
            v24bits=0x00000003,     ///<24 bits are sent per mono sample.
            v32bits=0x00000004,     ///<32 bits are sent per mono sample.
        };
        namespace mbselValC{
            constexpr MPL::Value<mbselVal,mbselVal::v8bits> v8bits{};
            constexpr MPL::Value<mbselVal,mbselVal::v9bits> v9bits{};
            constexpr MPL::Value<mbselVal,mbselVal::v16bits> v16bits{};
            constexpr MPL::Value<mbselVal,mbselVal::v24bits> v24bits{};
            constexpr MPL::Value<mbselVal,mbselVal::v32bits> v32bits{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(26,24),Register::ReadWriteAccess,mbselVal> mbsel{}; 
        ///Transmitter Enable. 
        enum class txenVal {
            disabled=0x00000000,     ///<Disable the I2S transmitter.
            enabled=0x00000001,     ///<Enable the I2S transmitter.
        };
        namespace txenValC{
            constexpr MPL::Value<txenVal,txenVal::disabled> disabled{};
            constexpr MPL::Value<txenVal,txenVal::enabled> enabled{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(29,29),Register::ReadWriteAccess,txenVal> txen{}; 
    }
    namespace Nonetxmode{    ///<Transmit Mode
        using Addr = Register::Address<0x4003a010,0xf0000000,0,unsigned>;
        ///Transmit Clock Cycle Select. 
        constexpr Register::BitLocation<Addr,Register::maskFromRange(11,0),Register::ReadWriteAccess,unsigned> cycle{}; 
        ///Transmit Start Control. 
        constexpr Register::BitLocation<Addr,Register::maskFromRange(19,12),Register::ReadWriteAccess,unsigned> start{}; 
        ///Transmit Drive Select. 
        constexpr Register::BitLocation<Addr,Register::maskFromRange(24,20),Register::ReadWriteAccess,unsigned> slots{}; 
        ///Transmit Drive Early Disable. 
        enum class dedisVal {
            inactive=0x00000000,     ///<Drive the output during every cycle of the transmitter's assigned slot(s), including the last clock cycle.
            active=0x00000001,     ///<Drive the output for every cycle of the transmitter's assigned slot(s), except for the last clock cycle of the last slot.
        };
        namespace dedisValC{
            constexpr MPL::Value<dedisVal,dedisVal::inactive> inactive{};
            constexpr MPL::Value<dedisVal,dedisVal::active> active{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(25,25),Register::ReadWriteAccess,dedisVal> dedis{}; 
        ///Transmit Drive Inactive Mode. 
        enum class dimdVal {
            zero=0x00000000,     ///<Drive zero on the data output pin during non-active slots.
            highZ=0x00000001,     ///<Don't drive the data output pin. The data output pin is tristated.
        };
        namespace dimdValC{
            constexpr MPL::Value<dimdVal,dimdVal::zero> zero{};
            constexpr MPL::Value<dimdVal,dimdVal::highZ> highZ{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(26,26),Register::ReadWriteAccess,dimdVal> dimd{}; 
        ///Transmit Time Division Multiplexing Enable. 
        enum class tdmenVal {
            disabled=0x00000000,     ///<Disable the time division multiplexing (TDM) feature.
            enabled=0x00000001,     ///<Enable the time division multiplexing (TDM) feature.
        };
        namespace tdmenValC{
            constexpr MPL::Value<tdmenVal,tdmenVal::disabled> disabled{};
            constexpr MPL::Value<tdmenVal,tdmenVal::enabled> enabled{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(27,27),Register::ReadWriteAccess,tdmenVal> tdmen{}; 
    }
    namespace Nonefsduty{    ///<Frame Sync Duty Cycle
        using Addr = Register::Address<0x4003a020,0x00000000,0,unsigned>;
        ///Frame Sync Low Time. 
        constexpr Register::BitLocation<Addr,Register::maskFromRange(15,0),Register::ReadWriteAccess,unsigned> fslow{}; 
        ///Frame Sync High Time. 
        constexpr Register::BitLocation<Addr,Register::maskFromRange(31,16),Register::ReadWriteAccess,unsigned> fshigh{}; 
    }
    namespace Nonerxcontrol{    ///<Receive Control
        using Addr = Register::Address<0x4003a030,0xffcc4400,0,unsigned>;
        ///Receive Initial Phase Delay. 
        constexpr Register::BitLocation<Addr,Register::maskFromRange(7,0),Register::ReadWriteAccess,unsigned> fsdel{}; 
        ///Receive Data Justification. 
        enum class jselVal {
            left=0x00000000,     ///<Use left-justified or I2S-style formats.
            right=0x00000001,     ///<Use right-justified format.
        };
        namespace jselValC{
            constexpr MPL::Value<jselVal,jselVal::left> left{};
            constexpr MPL::Value<jselVal,jselVal::right> right{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(8,8),Register::ReadWriteAccess,jselVal> jsel{}; 
        ///Receive Delay Disable. 
        enum class ddisVal {
            inactive=0x00000000,     ///<The first data bit is captured on the second or later rising edge of SCK after WS changes.
            active=0x00000001,     ///<The first data bit is captured by the receiver on the first rising edge of SCK after WS changes.
        };
        namespace ddisValC{
            constexpr MPL::Value<ddisVal,ddisVal::inactive> inactive{};
            constexpr MPL::Value<ddisVal,ddisVal::active> active{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(9,9),Register::ReadWriteAccess,ddisVal> ddis{}; 
        ///Receive WS Inversion Enable. 
        enum class fsinvenVal {
            disabled=0x00000000,     ///<Don't invert the WS signal. Use this setting for I2S format.
            enabled=0x00000001,     ///<Invert the WS signal.
        };
        namespace fsinvenValC{
            constexpr MPL::Value<fsinvenVal,fsinvenVal::disabled> disabled{};
            constexpr MPL::Value<fsinvenVal,fsinvenVal::enabled> enabled{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(11,11),Register::ReadWriteAccess,fsinvenVal> fsinven{}; 
        ///Receive SCK Inversion Enable. 
        enum class sclkinvenVal {
            disabled=0x00000000,     ///<Do not invert the receiver bit clock.
            enabled=0x00000001,     ///<Invert the receiver bit clock.
        };
        namespace sclkinvenValC{
            constexpr MPL::Value<sclkinvenVal,sclkinvenVal::disabled> disabled{};
            constexpr MPL::Value<sclkinvenVal,sclkinvenVal::enabled> enabled{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(12,12),Register::ReadWriteAccess,sclkinvenVal> sclkinven{}; 
        ///Receive Order. 
        enum class orderVal {
            leftRight=0x00000000,     ///<Left sample received first, right sample received second. Use this setting for I2S format.
            rightLeft=0x00000001,     ///<Right sample received first, left sample received second.
        };
        namespace orderValC{
            constexpr MPL::Value<orderVal,orderVal::leftRight> leftRight{};
            constexpr MPL::Value<orderVal,orderVal::rightLeft> rightLeft{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(13,13),Register::ReadWriteAccess,orderVal> order{}; 
        ///Receive Mono Bit-Width Select. 
        enum class mbselVal {
            v8bits=0x00000000,     ///<8 bits are received per mono sample.
            v9bits=0x00000001,     ///<9 bits are received per mono sample.
            v16bits=0x00000002,     ///<16 bits are received per mono sample.
            v24bits=0x00000003,     ///<24 bits are received per mono sample.
            v32bits=0x00000004,     ///<32 bits are received per mono sample.
        };
        namespace mbselValC{
            constexpr MPL::Value<mbselVal,mbselVal::v8bits> v8bits{};
            constexpr MPL::Value<mbselVal,mbselVal::v9bits> v9bits{};
            constexpr MPL::Value<mbselVal,mbselVal::v16bits> v16bits{};
            constexpr MPL::Value<mbselVal,mbselVal::v24bits> v24bits{};
            constexpr MPL::Value<mbselVal,mbselVal::v32bits> v32bits{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(17,15),Register::ReadWriteAccess,mbselVal> mbsel{}; 
        ///Receive Frame Sync Source Select. 
        enum class fssrcselVal {
            fsinExt=0x00000000,     ///<The word select or frame sync is input from the WS pin.
            fsinInt=0x00000001,     ///<The word select or frame sync is input from the internal DFS generator.
        };
        namespace fssrcselValC{
            constexpr MPL::Value<fssrcselVal,fssrcselVal::fsinExt> fsinExt{};
            constexpr MPL::Value<fssrcselVal,fssrcselVal::fsinInt> fsinInt{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(20,20),Register::ReadWriteAccess,fssrcselVal> fssrcsel{}; 
        ///Receive Enable. 
        enum class rxenVal {
            disabled=0x00000000,     ///<Disable the I2S receiver.
            enabled=0x00000001,     ///<Enable the I2S receiver.
        };
        namespace rxenValC{
            constexpr MPL::Value<rxenVal,rxenVal::disabled> disabled{};
            constexpr MPL::Value<rxenVal,rxenVal::enabled> enabled{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(21,21),Register::ReadWriteAccess,rxenVal> rxen{}; 
    }
    namespace Nonerxmode{    ///<Receive Mode
        using Addr = Register::Address<0x4003a040,0xf4000000,0,unsigned>;
        ///Receive Clock Cycle Select. 
        constexpr Register::BitLocation<Addr,Register::maskFromRange(11,0),Register::ReadWriteAccess,unsigned> cycle{}; 
        ///Receive Start Control. 
        constexpr Register::BitLocation<Addr,Register::maskFromRange(19,12),Register::ReadWriteAccess,unsigned> start{}; 
        ///Receive Drive Select. 
        constexpr Register::BitLocation<Addr,Register::maskFromRange(25,20),Register::ReadWriteAccess,unsigned> slots{}; 
        ///Receive Time Division Multiplexing Enable. 
        enum class tdmenVal {
            disabled=0x00000000,     ///<Disable the time division multiplexing (TDM) feature.
            enabled=0x00000001,     ///<Enable the time division multiplexing (TDM) feature.
        };
        namespace tdmenValC{
            constexpr MPL::Value<tdmenVal,tdmenVal::disabled> disabled{};
            constexpr MPL::Value<tdmenVal,tdmenVal::enabled> enabled{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(27,27),Register::ReadWriteAccess,tdmenVal> tdmen{}; 
    }
    namespace Noneclkcontrol{    ///<Clock Control
        using Addr = Register::Address<0x4003a050,0xf0000000,0,unsigned>;
        ///Clock Divider Integer Value. 
        constexpr Register::BitLocation<Addr,Register::maskFromRange(9,0),Register::ReadWriteAccess,unsigned> intdiv{}; 
        ///Clock Divider Fractional Value. 
        constexpr Register::BitLocation<Addr,Register::maskFromRange(17,10),Register::ReadWriteAccess,unsigned> fracdiv{}; 
        ///Duty Cycle Adjustment Mode. 
        enum class dutymdVal {
            more=0x00000000,     ///<When the division is fractional, the clock high time will be greater than 50% (by half of the source clock period).
            less=0x00000001,     ///<When the division is fractional, the clock low time will be greater than 50% (by half of the source clock period).
        };
        namespace dutymdValC{
            constexpr MPL::Value<dutymdVal,dutymdVal::more> more{};
            constexpr MPL::Value<dutymdVal,dutymdVal::less> less{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(18,18),Register::ReadWriteAccess,dutymdVal> dutymd{}; 
        ///Clock Divider Update. 
        enum class clkupdVal {
            update=0x00000001,     ///<Update the clock divider with new values of INTDIV, FRACDIV, and DIVEN.
        };
        namespace clkupdValC{
            constexpr MPL::Value<clkupdVal,clkupdVal::update> update{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(19,19),Register::ReadWriteAccess,clkupdVal> clkupd{}; 
        ///Clock Divider Enable. 
        enum class divenVal {
            disabled=0x00000000,     ///<Disable the clock divider.
            enabled=0x00000001,     ///<Enable the clock divider.
        };
        namespace divenValC{
            constexpr MPL::Value<divenVal,divenVal::disabled> disabled{};
            constexpr MPL::Value<divenVal,divenVal::enabled> enabled{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(20,20),Register::ReadWriteAccess,divenVal> diven{}; 
        ///Transmit Clock Select. 
        enum class txclkselVal {
            internal=0x00000000,     ///<The I2S transmitter is clocked from the internal clock divider.
            external=0x00000001,     ///<The I2S transmitter is clocked from the SCK pin.
        };
        namespace txclkselValC{
            constexpr MPL::Value<txclkselVal,txclkselVal::internal> internal{};
            constexpr MPL::Value<txclkselVal,txclkselVal::external> external{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(21,21),Register::ReadWriteAccess,txclkselVal> txclksel{}; 
        ///Receive Clock Select. 
        enum class rxclkselVal {
            internal=0x00000000,     ///<The I2S receiver is clocked from the internal clock divider.
            external=0x00000001,     ///<The I2S receiver is clocked from the SCK pin.
        };
        namespace rxclkselValC{
            constexpr MPL::Value<rxclkselVal,rxclkselVal::internal> internal{};
            constexpr MPL::Value<rxclkselVal,rxclkselVal::external> external{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(22,22),Register::ReadWriteAccess,rxclkselVal> rxclksel{}; 
        ///I2S Module Reset. 
        enum class resetVal {
            active=0x00000001,     ///<Reset the I2S module.
        };
        namespace resetValC{
            constexpr MPL::Value<resetVal,resetVal::active> active{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(23,23),Register::ReadWriteAccess,resetVal> reset{}; 
        ///Receive Clock Enable. 
        enum class rxclkenVal {
            disabled=0x00000000,     ///<Disable the I2S receiver clock.
            enabled=0x00000001,     ///<Enable the I2S receiver clock.
        };
        namespace rxclkenValC{
            constexpr MPL::Value<rxclkenVal,rxclkenVal::disabled> disabled{};
            constexpr MPL::Value<rxclkenVal,rxclkenVal::enabled> enabled{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(24,24),Register::ReadWriteAccess,rxclkenVal> rxclken{}; 
        ///Transmit Clock Enable. 
        enum class txclkenVal {
            disabled=0x00000000,     ///<Disable the I2S transmitter clock.
            enabled=0x00000001,     ///<Enable the I2S transmitter clock.
        };
        namespace txclkenValC{
            constexpr MPL::Value<txclkenVal,txclkenVal::disabled> disabled{};
            constexpr MPL::Value<txclkenVal,txclkenVal::enabled> enabled{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(25,25),Register::ReadWriteAccess,txclkenVal> txclken{}; 
        ///Receive SCK Mode. 
        enum class rxsclkmdVal {
            sckOutput=0x00000000,     ///<The I2S receiver SCK signal is an output.
            sckInput=0x00000001,     ///<The I2S receiver SCK signal is an input.
        };
        namespace rxsclkmdValC{
            constexpr MPL::Value<rxsclkmdVal,rxsclkmdVal::sckOutput> sckOutput{};
            constexpr MPL::Value<rxsclkmdVal,rxsclkmdVal::sckInput> sckInput{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(26,26),Register::ReadWriteAccess,rxsclkmdVal> rxsclkmd{}; 
        ///Transmit SCK Mode. 
        enum class txsclkmdVal {
            sckOutput=0x00000000,     ///<The I2S transmitter SCK signal is an output.
            sckInput=0x00000001,     ///<The I2S transmitter SCK signal is an input.
        };
        namespace txsclkmdValC{
            constexpr MPL::Value<txsclkmdVal,txsclkmdVal::sckOutput> sckOutput{};
            constexpr MPL::Value<txsclkmdVal,txsclkmdVal::sckInput> sckInput{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(27,27),Register::ReadWriteAccess,txsclkmdVal> txsclkmd{}; 
    }
    namespace Nonetxfifo{    ///<Transmit Data FIFO
        using Addr = Register::Address<0x4003a060,0x00000000,0,unsigned>;
        ///Transmit Data FIFO. 
        constexpr Register::BitLocation<Addr,Register::maskFromRange(31,0),Register::ReadWriteAccess,unsigned> txfifo{}; 
    }
    namespace Nonerxfifo{    ///<Receive Data FIFO
        using Addr = Register::Address<0x4003a070,0x00000000,0,unsigned>;
        ///Receive Data FIFO. 
        constexpr Register::BitLocation<Addr,Register::maskFromRange(31,0),Register::ReadWriteAccess,unsigned> rxfifo{}; 
    }
    namespace Nonefifostatus{    ///<FIFO Status
        using Addr = Register::Address<0x4003a080,0xfff0fff0,0,unsigned>;
        ///Transmit FIFO Status. 
        constexpr Register::BitLocation<Addr,Register::maskFromRange(3,0),Register::ReadWriteAccess,unsigned> txfifonum{}; 
        ///Receive FIFO Status. 
        constexpr Register::BitLocation<Addr,Register::maskFromRange(19,16),Register::ReadWriteAccess,unsigned> rxfifonum{}; 
    }
    namespace Nonefifocontrol{    ///<FIFO Control
        using Addr = Register::Address<0x4003a090,0xff90fff0,0,unsigned>;
        ///Transmit FIFO Low Watermark. 
        constexpr Register::BitLocation<Addr,Register::maskFromRange(3,0),Register::ReadWriteAccess,unsigned> txfifowm{}; 
        ///Receive FIFO High Watermark. 
        constexpr Register::BitLocation<Addr,Register::maskFromRange(19,16),Register::ReadWriteAccess,unsigned> rxfifowm{}; 
        ///Transmit FIFO Flush. 
        enum class txfifoflVal {
            set=0x00000001,     ///<Flush the I2S transmitter FIFO.
        };
        namespace txfifoflValC{
            constexpr MPL::Value<txfifoflVal,txfifoflVal::set> set{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(21,21),Register::ReadWriteAccess,txfifoflVal> txfifofl{}; 
        ///Receive FIFO Flush. 
        enum class rxfifoflVal {
            set=0x00000001,     ///<Flush the I2S receiver FIFO.
        };
        namespace rxfifoflValC{
            constexpr MPL::Value<rxfifoflVal,rxfifoflVal::set> set{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(22,22),Register::ReadWriteAccess,rxfifoflVal> rxfifofl{}; 
    }
    namespace Noneintcontrol{    ///<Interrupt Control
        using Addr = Register::Address<0x4003a0a0,0xfffffff0,0,unsigned>;
        ///Transmit Underflow Interrupt Enable. 
        enum class txufienVal {
            disabled=0x00000000,     ///<Disable the transmit underflow interrupt.
            enabled=0x00000001,     ///<Enable the transmit underflow interrupt.
        };
        namespace txufienValC{
            constexpr MPL::Value<txufienVal,txufienVal::disabled> disabled{};
            constexpr MPL::Value<txufienVal,txufienVal::enabled> enabled{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,txufienVal> txufien{}; 
        ///Receive Overflow Interrupt Enable. 
        enum class rxofienVal {
            disabled=0x00000000,     ///<Disable the receive overflow interrupt.
            enabled=0x00000001,     ///<Enable the receive overflow interrupt.
        };
        namespace rxofienValC{
            constexpr MPL::Value<rxofienVal,rxofienVal::disabled> disabled{};
            constexpr MPL::Value<rxofienVal,rxofienVal::enabled> enabled{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,rxofienVal> rxofien{}; 
        ///Transmit FIFO Low Watermark Interrupt Enable. 
        enum class txlwmienVal {
            disabled=0x00000000,     ///<Disable the transmit FIFO low watermark interrupt.
            enabled=0x00000001,     ///<Enable the transmit FIFO low watermark interrupt.
        };
        namespace txlwmienValC{
            constexpr MPL::Value<txlwmienVal,txlwmienVal::disabled> disabled{};
            constexpr MPL::Value<txlwmienVal,txlwmienVal::enabled> enabled{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,txlwmienVal> txlwmien{}; 
        ///Receive FIFO High Watermark Interrupt Enable. 
        enum class rxhwmienVal {
            disabled=0x00000000,     ///<Disable the receive FIFO high watermark interrupt.
            enabled=0x00000001,     ///<Enable the receive FIFO high watermark interrupt.
        };
        namespace rxhwmienValC{
            constexpr MPL::Value<rxhwmienVal,rxhwmienVal::disabled> disabled{};
            constexpr MPL::Value<rxhwmienVal,rxhwmienVal::enabled> enabled{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,rxhwmienVal> rxhwmien{}; 
    }
    namespace Nonestatus{    ///<Module Status
        using Addr = Register::Address<0x4003a0b0,0xfffffc00,0,unsigned>;
        ///Transmit Underflow Interrupt Flag. 
        enum class txufiVal {
            notSet=0x00000000,     ///<A transmit underflow has not occurred.
            set=0x00000001,     ///<A transmit underflow occurred.
        };
        namespace txufiValC{
            constexpr MPL::Value<txufiVal,txufiVal::notSet> notSet{};
            constexpr MPL::Value<txufiVal,txufiVal::set> set{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,txufiVal> txufi{}; 
        ///Receive Overflow Interrupt Flag. 
        enum class rxofiVal {
            notSet=0x00000000,     ///<A receive overflow has not occurred.
            set=0x00000001,     ///<A receive overflow occurred.
        };
        namespace rxofiValC{
            constexpr MPL::Value<rxofiVal,rxofiVal::notSet> notSet{};
            constexpr MPL::Value<rxofiVal,rxofiVal::set> set{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,rxofiVal> rxofi{}; 
        ///Transmit FIFO Low Watermark Interrupt Flag. 
        enum class txlwmiVal {
            notSet=0x00000000,     ///<Transmit FIFO level is above the low watermark.
            set=0x00000001,     ///<Transmit FIFO level is at or below the low watermark.
        };
        namespace txlwmiValC{
            constexpr MPL::Value<txlwmiVal,txlwmiVal::notSet> notSet{};
            constexpr MPL::Value<txlwmiVal,txlwmiVal::set> set{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,txlwmiVal> txlwmi{}; 
        ///Receive FIFO High Watermark Interrupt Flag. 
        enum class rxhwmiVal {
            notSet=0x00000000,     ///<Receive FIFO level is below the high watermark.
            set=0x00000001,     ///<Receive FIFO level is at or above the high watermark.
        };
        namespace rxhwmiValC{
            constexpr MPL::Value<rxhwmiVal,rxhwmiVal::notSet> notSet{};
            constexpr MPL::Value<rxhwmiVal,rxhwmiVal::set> set{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,rxhwmiVal> rxhwmi{}; 
        ///Clock Divider Busy Flag. 
        enum class cdbusyfVal {
            notBusy=0x00000000,     ///<The divider is not busy and an update is not pending.
            busy=0x00000001,     ///<The divider is busy and an update is pending.
        };
        namespace cdbusyfValC{
            constexpr MPL::Value<cdbusyfVal,cdbusyfVal::notBusy> notBusy{};
            constexpr MPL::Value<cdbusyfVal,cdbusyfVal::busy> busy{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(4,4),Register::ReadWriteAccess,cdbusyfVal> cdbusyf{}; 
        ///Clock Divider Counter Status. 
        enum class cdstsVal {
            running=0x00000000,     ///<Divided clock output is running.
            halted=0x00000001,     ///<Divided clock output is halted.
        };
        namespace cdstsValC{
            constexpr MPL::Value<cdstsVal,cdstsVal::running> running{};
            constexpr MPL::Value<cdstsVal,cdstsVal::halted> halted{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(5,5),Register::ReadWriteAccess,cdstsVal> cdsts{}; 
        ///Transmit Clock Select Ready Flag. 
        enum class txclkselrfVal {
            notSet=0x00000000,     ///<The transmit clock is not synchronized.
            set=0x00000001,     ///<The transmit clock is synchronized and the transmitter is ready to send data.
        };
        namespace txclkselrfValC{
            constexpr MPL::Value<txclkselrfVal,txclkselrfVal::notSet> notSet{};
            constexpr MPL::Value<txclkselrfVal,txclkselrfVal::set> set{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(6,6),Register::ReadWriteAccess,txclkselrfVal> txclkselrf{}; 
        ///Receive Clock Select Ready Flag. 
        enum class rxclkselrfVal {
            notSet=0x00000000,     ///<The receive clock is not synchronized.
            set=0x00000001,     ///<The receive clock is synchronized and the receiver is ready to accept data.
        };
        namespace rxclkselrfValC{
            constexpr MPL::Value<rxclkselrfVal,rxclkselrfVal::notSet> notSet{};
            constexpr MPL::Value<rxclkselrfVal,rxclkselrfVal::set> set{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(7,7),Register::ReadWriteAccess,rxclkselrfVal> rxclkselrf{}; 
        ///Transmit Clock Enable Ready Flag. 
        enum class txclkenrfVal {
            notSet=0x00000000,     ///<The transmit clock is not synchronized.
            set=0x00000001,     ///<The transmit clock is synchronized and the transmitter is ready to send data.
        };
        namespace txclkenrfValC{
            constexpr MPL::Value<txclkenrfVal,txclkenrfVal::notSet> notSet{};
            constexpr MPL::Value<txclkenrfVal,txclkenrfVal::set> set{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(8,8),Register::ReadWriteAccess,txclkenrfVal> txclkenrf{}; 
        ///Receive Clock Enable Ready Flag. 
        enum class rxclkenrfVal {
            notSet=0x00000000,     ///<The receive clock is not synchronized.
            set=0x00000001,     ///<The receive clock is synchronized and the receiver is ready to accept data.
        };
        namespace rxclkenrfValC{
            constexpr MPL::Value<rxclkenrfVal,rxclkenrfVal::notSet> notSet{};
            constexpr MPL::Value<rxclkenrfVal,rxclkenrfVal::set> set{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(9,9),Register::ReadWriteAccess,rxclkenrfVal> rxclkenrf{}; 
    }
    namespace Nonedmacontrol{    ///<DMA Control
        using Addr = Register::Address<0x4003a0c0,0xfffffff0,0,unsigned>;
        ///Transmit DMA Enable. 
        enum class txdmaenVal {
            disabled=0x00000000,     ///<Disable transmitter DMA data requests.
            enabled=0x00000001,     ///<Enable transmitter DMA data requests.
        };
        namespace txdmaenValC{
            constexpr MPL::Value<txdmaenVal,txdmaenVal::disabled> disabled{};
            constexpr MPL::Value<txdmaenVal,txdmaenVal::enabled> enabled{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,txdmaenVal> txdmaen{}; 
        ///Receive DMA Enable. 
        enum class rxdmaenVal {
            disabled=0x00000000,     ///<Disable receiver DMA data transfer requests.
            enabled=0x00000001,     ///<Enable receiver DMA data transfer requests.
        };
        namespace rxdmaenValC{
            constexpr MPL::Value<rxdmaenVal,rxdmaenVal::disabled> disabled{};
            constexpr MPL::Value<rxdmaenVal,rxdmaenVal::enabled> enabled{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,rxdmaenVal> rxdmaen{}; 
        ///Transmit DMA Burst Mode. 
        enum class txdmabmdVal {
            oneWord=0x00000000,     ///<The transmitter transmits one word at a time. Whenever there is any room in the transmit FIFO, a single word burst DMA data request is generated.
            fourWords=0x00000001,     ///<The transmitter transmits four words at a time. Whenever the FIFO depth drops below five, a DMA burst request is generated for four words.
        };
        namespace txdmabmdValC{
            constexpr MPL::Value<txdmabmdVal,txdmabmdVal::oneWord> oneWord{};
            constexpr MPL::Value<txdmabmdVal,txdmabmdVal::fourWords> fourWords{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,txdmabmdVal> txdmabmd{}; 
        ///Receive DMA Burst Mode. 
        enum class rxdmabmdVal {
            oneWord=0x00000000,     ///<The receiver receives one word at a time. Whenever there is at least one word in the receive FIFO, a single word burst DMA request is generated.
            fourWords=0x00000001,     ///<The receiver receives four words at a time. Whenever the FIFO depth rises above three, a DMA burst request is generated for four words.
        };
        namespace rxdmabmdValC{
            constexpr MPL::Value<rxdmabmdVal,rxdmabmdVal::oneWord> oneWord{};
            constexpr MPL::Value<rxdmabmdVal,rxdmabmdVal::fourWords> fourWords{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,rxdmabmdVal> rxdmabmd{}; 
    }
    namespace Nonedbgcontrol{    ///<Debug Control
        using Addr = Register::Address<0x4003a0d0,0xfffffff0,0,unsigned>;
        ///I2S Transmit DMA Debug Halt Enable. 
        enum class txdbghenVal {
            disabled=0x00000000,     ///<Transmit DMA requests continue while the core is debug mode.
            enabled=0x00000001,     ///<Transmit DMA requests stop while the core is debug mode.
        };
        namespace txdbghenValC{
            constexpr MPL::Value<txdbghenVal,txdbghenVal::disabled> disabled{};
            constexpr MPL::Value<txdbghenVal,txdbghenVal::enabled> enabled{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,txdbghenVal> txdbghen{}; 
        ///I2S Receive DMA Debug Halt Enable. 
        enum class rxdbghenVal {
            disabled=0x00000000,     ///<Receive DMA requests continue while the core is debug mode.
            enabled=0x00000001,     ///<Receive DMA requests stop while the core is debug mode.
        };
        namespace rxdbghenValC{
            constexpr MPL::Value<rxdbghenVal,rxdbghenVal::disabled> disabled{};
            constexpr MPL::Value<rxdbghenVal,rxdbghenVal::enabled> enabled{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,rxdbghenVal> rxdbghen{}; 
        ///I2S Transmit Debug Mode. 
        enum class txdbgmdVal {
            run=0x00000000,     ///<The clock to the I2S transmitter is active in debug mode.
            halt=0x00000001,     ///<The clock to the I2S transmitter is not active in debug mode. The clock divider keeps running and the clock will be disabled when two samples are ready to be sent by the transmitter.
        };
        namespace txdbgmdValC{
            constexpr MPL::Value<txdbgmdVal,txdbgmdVal::run> run{};
            constexpr MPL::Value<txdbgmdVal,txdbgmdVal::halt> halt{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,txdbgmdVal> txdbgmd{}; 
        ///I2S Receive Debug Mode. 
        enum class rxdbgmdVal {
            run=0x00000000,     ///<The clock to the I2S receiver is active in debug mode.
            halt=0x00000001,     ///<The clock to the I2S receiver is not active in debug mode. The clock divider keeps running and the clock will be disabled when two samples are captured in the receiver.
        };
        namespace rxdbgmdValC{
            constexpr MPL::Value<rxdbgmdVal,rxdbgmdVal::run> run{};
            constexpr MPL::Value<rxdbgmdVal,rxdbgmdVal::halt> halt{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,rxdbgmdVal> rxdbgmd{}; 
    }
}