#pragma once 
#include "Register/Utility.hpp"
namespace Kvasir {
//Advanced Encryption Standard
    namespace AesCr{    ///<Control Register
        using Addr = Register::Address<0xf000c000,0xfffffefe,0,unsigned>;
        ///Start Processing
        constexpr Register::BitLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,unsigned> start{}; 
        ///Software Reset
        constexpr Register::BitLocation<Addr,Register::maskFromRange(8,8),Register::ReadWriteAccess,unsigned> swrst{}; 
    }
    namespace AesMr{    ///<Mode Register
        using Addr = Register::Address<0xf000c004,0xff080006,0,unsigned>;
        ///Processing Mode
        constexpr Register::BitLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,unsigned> cipher{}; 
        ///Dual Input BUFFer
        enum class dualbuffVal {
            inactive=0x00000000,     ///<AES_IDATARx cannot be written during processing of previous block.
            active=0x00000001,     ///<AES_IDATARx can be written during processing of previous block when SMOD = 0x2. It speeds up the overall runtime of large files.
        };
        namespace dualbuffValC{
            constexpr MPL::Value<dualbuffVal,dualbuffVal::inactive> inactive{};
            constexpr MPL::Value<dualbuffVal,dualbuffVal::active> active{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,dualbuffVal> dualbuff{}; 
        ///Processing Delay
        constexpr Register::BitLocation<Addr,Register::maskFromRange(7,4),Register::ReadWriteAccess,unsigned> procdly{}; 
        ///Start Mode
        enum class smodVal {
            manualStart=0x00000000,     ///<Manual Mode
            autoStart=0x00000001,     ///<Auto Mode
            idatar0Start=0x00000002,     ///<AES_IDATAR0 access only Auto Mode
        };
        namespace smodValC{
            constexpr MPL::Value<smodVal,smodVal::manualStart> manualStart{};
            constexpr MPL::Value<smodVal,smodVal::autoStart> autoStart{};
            constexpr MPL::Value<smodVal,smodVal::idatar0Start> idatar0Start{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(9,8),Register::ReadWriteAccess,smodVal> smod{}; 
        ///Key Size
        enum class keysizeVal {
            aes128=0x00000000,     ///<AES Key Size is 128 bits
            aes192=0x00000001,     ///<AES Key Size is 192 bits
            aes256=0x00000002,     ///<AES Key Size is 256 bits
        };
        namespace keysizeValC{
            constexpr MPL::Value<keysizeVal,keysizeVal::aes128> aes128{};
            constexpr MPL::Value<keysizeVal,keysizeVal::aes192> aes192{};
            constexpr MPL::Value<keysizeVal,keysizeVal::aes256> aes256{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(11,10),Register::ReadWriteAccess,keysizeVal> keysize{}; 
        ///Operation Mode
        enum class opmodVal {
            ecb=0x00000000,     ///<ECB: Electronic Code Book mode
            cbc=0x00000001,     ///<CBC: Cipher Block Chaining mode
            ofb=0x00000002,     ///<OFB: Output Feedback mode
            cfb=0x00000003,     ///<CFB: Cipher Feedback mode
            ctr=0x00000004,     ///<CTR: Counter mode (16-bit internal counter)
        };
        namespace opmodValC{
            constexpr MPL::Value<opmodVal,opmodVal::ecb> ecb{};
            constexpr MPL::Value<opmodVal,opmodVal::cbc> cbc{};
            constexpr MPL::Value<opmodVal,opmodVal::ofb> ofb{};
            constexpr MPL::Value<opmodVal,opmodVal::cfb> cfb{};
            constexpr MPL::Value<opmodVal,opmodVal::ctr> ctr{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(14,12),Register::ReadWriteAccess,opmodVal> opmod{}; 
        ///Last Output Data Mode
        constexpr Register::BitLocation<Addr,Register::maskFromRange(15,15),Register::ReadWriteAccess,unsigned> lod{}; 
        ///Cipher Feedback Data Size
        enum class cfbsVal {
            size128bit=0x00000000,     ///<128-bit
            size64bit=0x00000001,     ///<64-bit
            size32bit=0x00000002,     ///<32-bit
            size16bit=0x00000003,     ///<16-bit
            size8bit=0x00000004,     ///<8-bit
        };
        namespace cfbsValC{
            constexpr MPL::Value<cfbsVal,cfbsVal::size128bit> size128bit{};
            constexpr MPL::Value<cfbsVal,cfbsVal::size64bit> size64bit{};
            constexpr MPL::Value<cfbsVal,cfbsVal::size32bit> size32bit{};
            constexpr MPL::Value<cfbsVal,cfbsVal::size16bit> size16bit{};
            constexpr MPL::Value<cfbsVal,cfbsVal::size8bit> size8bit{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(18,16),Register::ReadWriteAccess,cfbsVal> cfbs{}; 
        ///Key
        constexpr Register::BitLocation<Addr,Register::maskFromRange(23,20),Register::ReadWriteAccess,unsigned> ckey{}; 
    }
    namespace AesIer{    ///<Interrupt Enable Register
        using Addr = Register::Address<0xf000c010,0xfffffefe,0,unsigned>;
        ///Data Ready Interrupt Enable
        constexpr Register::BitLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,unsigned> datrdy{}; 
        ///Unspecified Register Access Detection Interrupt Enable
        constexpr Register::BitLocation<Addr,Register::maskFromRange(8,8),Register::ReadWriteAccess,unsigned> urad{}; 
    }
    namespace AesIdr{    ///<Interrupt Disable Register
        using Addr = Register::Address<0xf000c014,0xfffffefe,0,unsigned>;
        ///Data Ready Interrupt Disable
        constexpr Register::BitLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,unsigned> datrdy{}; 
        ///Unspecified Register Access Detection Interrupt Disable
        constexpr Register::BitLocation<Addr,Register::maskFromRange(8,8),Register::ReadWriteAccess,unsigned> urad{}; 
    }
    namespace AesImr{    ///<Interrupt Mask Register
        using Addr = Register::Address<0xf000c018,0xfffffefe,0,unsigned>;
        ///Data Ready Interrupt Mask
        constexpr Register::BitLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,unsigned> datrdy{}; 
        ///Unspecified Register Access Detection Interrupt Mask
        constexpr Register::BitLocation<Addr,Register::maskFromRange(8,8),Register::ReadWriteAccess,unsigned> urad{}; 
    }
    namespace AesIsr{    ///<Interrupt Status Register
        using Addr = Register::Address<0xf000c01c,0xffff0efe,0,unsigned>;
        ///Data Ready
        constexpr Register::BitLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,unsigned> datrdy{}; 
        ///Unspecified Register Access Detection Status
        constexpr Register::BitLocation<Addr,Register::maskFromRange(8,8),Register::ReadWriteAccess,unsigned> urad{}; 
        ///Unspecified Register Access:
        enum class uratVal {
            idrWrProcessing=0x00000000,     ///<Input Data Register written during the data processing when SMOD=0x2 mode.
            odrRdProcessing=0x00000001,     ///<Output Data Register read during the data processing.
            mrWrProcessing=0x00000002,     ///<Mode Register written during the data processing.
            odrRdSubkgen=0x00000003,     ///<Output Data Register read during the sub-keys generation.
            mrWrSubkgen=0x00000004,     ///<Mode Register written during the sub-keys generation.
            worRdAccess=0x00000005,     ///<Write-only register read access.
        };
        namespace uratValC{
            constexpr MPL::Value<uratVal,uratVal::idrWrProcessing> idrWrProcessing{};
            constexpr MPL::Value<uratVal,uratVal::odrRdProcessing> odrRdProcessing{};
            constexpr MPL::Value<uratVal,uratVal::mrWrProcessing> mrWrProcessing{};
            constexpr MPL::Value<uratVal,uratVal::odrRdSubkgen> odrRdSubkgen{};
            constexpr MPL::Value<uratVal,uratVal::mrWrSubkgen> mrWrSubkgen{};
            constexpr MPL::Value<uratVal,uratVal::worRdAccess> worRdAccess{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(15,12),Register::ReadWriteAccess,uratVal> urat{}; 
    }
    namespace AesKeywr0{    ///<Key Word Register
        using Addr = Register::Address<0xf000c020,0x00000000,0,unsigned>;
        ///Key Word
        constexpr Register::BitLocation<Addr,Register::maskFromRange(31,0),Register::ReadWriteAccess,unsigned> keyw{}; 
    }
    namespace AesKeywr1{    ///<Key Word Register
        using Addr = Register::Address<0xf000c024,0x00000000,0,unsigned>;
        ///Key Word
        constexpr Register::BitLocation<Addr,Register::maskFromRange(31,0),Register::ReadWriteAccess,unsigned> keyw{}; 
    }
    namespace AesKeywr2{    ///<Key Word Register
        using Addr = Register::Address<0xf000c028,0x00000000,0,unsigned>;
        ///Key Word
        constexpr Register::BitLocation<Addr,Register::maskFromRange(31,0),Register::ReadWriteAccess,unsigned> keyw{}; 
    }
    namespace AesKeywr3{    ///<Key Word Register
        using Addr = Register::Address<0xf000c02c,0x00000000,0,unsigned>;
        ///Key Word
        constexpr Register::BitLocation<Addr,Register::maskFromRange(31,0),Register::ReadWriteAccess,unsigned> keyw{}; 
    }
    namespace AesKeywr4{    ///<Key Word Register
        using Addr = Register::Address<0xf000c030,0x00000000,0,unsigned>;
        ///Key Word
        constexpr Register::BitLocation<Addr,Register::maskFromRange(31,0),Register::ReadWriteAccess,unsigned> keyw{}; 
    }
    namespace AesKeywr5{    ///<Key Word Register
        using Addr = Register::Address<0xf000c034,0x00000000,0,unsigned>;
        ///Key Word
        constexpr Register::BitLocation<Addr,Register::maskFromRange(31,0),Register::ReadWriteAccess,unsigned> keyw{}; 
    }
    namespace AesKeywr6{    ///<Key Word Register
        using Addr = Register::Address<0xf000c038,0x00000000,0,unsigned>;
        ///Key Word
        constexpr Register::BitLocation<Addr,Register::maskFromRange(31,0),Register::ReadWriteAccess,unsigned> keyw{}; 
    }
    namespace AesKeywr7{    ///<Key Word Register
        using Addr = Register::Address<0xf000c03c,0x00000000,0,unsigned>;
        ///Key Word
        constexpr Register::BitLocation<Addr,Register::maskFromRange(31,0),Register::ReadWriteAccess,unsigned> keyw{}; 
    }
    namespace AesIdatar0{    ///<Input Data Register
        using Addr = Register::Address<0xf000c040,0x00000000,0,unsigned>;
        ///Input Data Word
        constexpr Register::BitLocation<Addr,Register::maskFromRange(31,0),Register::ReadWriteAccess,unsigned> idata{}; 
    }
    namespace AesIdatar1{    ///<Input Data Register
        using Addr = Register::Address<0xf000c044,0x00000000,0,unsigned>;
        ///Input Data Word
        constexpr Register::BitLocation<Addr,Register::maskFromRange(31,0),Register::ReadWriteAccess,unsigned> idata{}; 
    }
    namespace AesIdatar2{    ///<Input Data Register
        using Addr = Register::Address<0xf000c048,0x00000000,0,unsigned>;
        ///Input Data Word
        constexpr Register::BitLocation<Addr,Register::maskFromRange(31,0),Register::ReadWriteAccess,unsigned> idata{}; 
    }
    namespace AesIdatar3{    ///<Input Data Register
        using Addr = Register::Address<0xf000c04c,0x00000000,0,unsigned>;
        ///Input Data Word
        constexpr Register::BitLocation<Addr,Register::maskFromRange(31,0),Register::ReadWriteAccess,unsigned> idata{}; 
    }
    namespace AesOdatar0{    ///<Output Data Register
        using Addr = Register::Address<0xf000c050,0x00000000,0,unsigned>;
        ///Output Data
        constexpr Register::BitLocation<Addr,Register::maskFromRange(31,0),Register::ReadWriteAccess,unsigned> odata{}; 
    }
    namespace AesOdatar1{    ///<Output Data Register
        using Addr = Register::Address<0xf000c054,0x00000000,0,unsigned>;
        ///Output Data
        constexpr Register::BitLocation<Addr,Register::maskFromRange(31,0),Register::ReadWriteAccess,unsigned> odata{}; 
    }
    namespace AesOdatar2{    ///<Output Data Register
        using Addr = Register::Address<0xf000c058,0x00000000,0,unsigned>;
        ///Output Data
        constexpr Register::BitLocation<Addr,Register::maskFromRange(31,0),Register::ReadWriteAccess,unsigned> odata{}; 
    }
    namespace AesOdatar3{    ///<Output Data Register
        using Addr = Register::Address<0xf000c05c,0x00000000,0,unsigned>;
        ///Output Data
        constexpr Register::BitLocation<Addr,Register::maskFromRange(31,0),Register::ReadWriteAccess,unsigned> odata{}; 
    }
    namespace AesIvr0{    ///<Initialization Vector Register
        using Addr = Register::Address<0xf000c060,0x00000000,0,unsigned>;
        ///Initialization Vector
        constexpr Register::BitLocation<Addr,Register::maskFromRange(31,0),Register::ReadWriteAccess,unsigned> iv{}; 
    }
    namespace AesIvr1{    ///<Initialization Vector Register
        using Addr = Register::Address<0xf000c064,0x00000000,0,unsigned>;
        ///Initialization Vector
        constexpr Register::BitLocation<Addr,Register::maskFromRange(31,0),Register::ReadWriteAccess,unsigned> iv{}; 
    }
    namespace AesIvr2{    ///<Initialization Vector Register
        using Addr = Register::Address<0xf000c068,0x00000000,0,unsigned>;
        ///Initialization Vector
        constexpr Register::BitLocation<Addr,Register::maskFromRange(31,0),Register::ReadWriteAccess,unsigned> iv{}; 
    }
    namespace AesIvr3{    ///<Initialization Vector Register
        using Addr = Register::Address<0xf000c06c,0x00000000,0,unsigned>;
        ///Initialization Vector
        constexpr Register::BitLocation<Addr,Register::maskFromRange(31,0),Register::ReadWriteAccess,unsigned> iv{}; 
    }
}