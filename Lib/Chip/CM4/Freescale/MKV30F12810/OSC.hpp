#pragma once 
#include <Register/Utility.hpp>
namespace Kvasir {
//Oscillator
    namespace OscCr{    ///<OSC Control Register
        using Addr = Register::Address<0x40065000,0xffffff50,0x00000000,unsigned char>;
        ///Oscillator 16 pF Capacitor Load Configure
        enum class Sc16pVal {
            v0=0x00000000,     ///<Disable the selection.
            v1=0x00000001,     ///<Add 16 pF capacitor to the oscillator load.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,Sc16pVal> sc16p{}; 
        namespace Sc16pValC{
            constexpr Register::FieldValue<decltype(sc16p)::Type,Sc16pVal::v0> v0{};
            constexpr Register::FieldValue<decltype(sc16p)::Type,Sc16pVal::v1> v1{};
        }
        ///Oscillator 8 pF Capacitor Load Configure
        enum class Sc8pVal {
            v0=0x00000000,     ///<Disable the selection.
            v1=0x00000001,     ///<Add 8 pF capacitor to the oscillator load.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,Sc8pVal> sc8p{}; 
        namespace Sc8pValC{
            constexpr Register::FieldValue<decltype(sc8p)::Type,Sc8pVal::v0> v0{};
            constexpr Register::FieldValue<decltype(sc8p)::Type,Sc8pVal::v1> v1{};
        }
        ///Oscillator 4 pF Capacitor Load Configure
        enum class Sc4pVal {
            v0=0x00000000,     ///<Disable the selection.
            v1=0x00000001,     ///<Add 4 pF capacitor to the oscillator load.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,Sc4pVal> sc4p{}; 
        namespace Sc4pValC{
            constexpr Register::FieldValue<decltype(sc4p)::Type,Sc4pVal::v0> v0{};
            constexpr Register::FieldValue<decltype(sc4p)::Type,Sc4pVal::v1> v1{};
        }
        ///Oscillator 2 pF Capacitor Load Configure
        enum class Sc2pVal {
            v0=0x00000000,     ///<Disable the selection.
            v1=0x00000001,     ///<Add 2 pF capacitor to the oscillator load.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,Sc2pVal> sc2p{}; 
        namespace Sc2pValC{
            constexpr Register::FieldValue<decltype(sc2p)::Type,Sc2pVal::v0> v0{};
            constexpr Register::FieldValue<decltype(sc2p)::Type,Sc2pVal::v1> v1{};
        }
        ///External Reference Stop Enable
        enum class ErefstenVal {
            v0=0x00000000,     ///<External reference clock is disabled in Stop mode.
            v1=0x00000001,     ///<External reference clock stays enabled in Stop mode if ERCLKEN is set before entering Stop mode.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(5,5),Register::ReadWriteAccess,ErefstenVal> erefsten{}; 
        namespace ErefstenValC{
            constexpr Register::FieldValue<decltype(erefsten)::Type,ErefstenVal::v0> v0{};
            constexpr Register::FieldValue<decltype(erefsten)::Type,ErefstenVal::v1> v1{};
        }
        ///External Reference Enable
        enum class ErclkenVal {
            v0=0x00000000,     ///<External reference clock is inactive.
            v1=0x00000001,     ///<External reference clock is enabled.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,7),Register::ReadWriteAccess,ErclkenVal> erclken{}; 
        namespace ErclkenValC{
            constexpr Register::FieldValue<decltype(erclken)::Type,ErclkenVal::v0> v0{};
            constexpr Register::FieldValue<decltype(erclken)::Type,ErclkenVal::v1> v1{};
        }
    }
    namespace OscDiv{    ///<OSC_DIV
        using Addr = Register::Address<0x40065002,0xffffff3f,0x00000000,unsigned char>;
        ///no description available
        enum class ErpsVal {
            v00=0x00000000,     ///<The divisor ratio is 1.
            v01=0x00000001,     ///<The divisor ratio is 2.
            v10=0x00000002,     ///<The divisor ratio is 4.
            v11=0x00000003,     ///<The divisor ratio is 8.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,6),Register::ReadWriteAccess,ErpsVal> erps{}; 
        namespace ErpsValC{
            constexpr Register::FieldValue<decltype(erps)::Type,ErpsVal::v00> v00{};
            constexpr Register::FieldValue<decltype(erps)::Type,ErpsVal::v01> v01{};
            constexpr Register::FieldValue<decltype(erps)::Type,ErpsVal::v10> v10{};
            constexpr Register::FieldValue<decltype(erps)::Type,ErpsVal::v11> v11{};
        }
    }
}
