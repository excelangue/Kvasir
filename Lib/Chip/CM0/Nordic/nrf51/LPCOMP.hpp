#pragma once 
#include <Register/Utility.hpp>
namespace Kvasir {
//Low power comparator.
    namespace LpcompTasksStart{    ///<Start the comparator.
        using Addr = Register::Address<0x40013000,0xffffffff,0x00000000,unsigned>;
    }
    namespace LpcompTasksStop{    ///<Stop the comparator.
        using Addr = Register::Address<0x40013004,0xffffffff,0x00000000,unsigned>;
    }
    namespace LpcompTasksSample{    ///<Sample comparator value.
        using Addr = Register::Address<0x40013008,0xffffffff,0x00000000,unsigned>;
    }
    namespace LpcompEventsReady{    ///<LPCOMP is ready and output is valid.
        using Addr = Register::Address<0x40013100,0xffffffff,0x00000000,unsigned>;
    }
    namespace LpcompEventsDown{    ///<Input voltage crossed the threshold going down.
        using Addr = Register::Address<0x40013104,0xffffffff,0x00000000,unsigned>;
    }
    namespace LpcompEventsUp{    ///<Input voltage crossed the threshold going up.
        using Addr = Register::Address<0x40013108,0xffffffff,0x00000000,unsigned>;
    }
    namespace LpcompEventsCross{    ///<Input voltage crossed the threshold in any direction.
        using Addr = Register::Address<0x4001310c,0xffffffff,0x00000000,unsigned>;
    }
    namespace LpcompShorts{    ///<Shortcuts for the LPCOMP.
        using Addr = Register::Address<0x40013200,0xffffffe0,0x00000000,unsigned>;
        ///Shortcut between READY event and SAMPLE task.
        enum class ReadysampleVal {
            disabled=0x00000000,     ///<Shortcut disabled.
            enabled=0x00000001,     ///<Shortcut enabled.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,ReadysampleVal> readySample{}; 
        namespace ReadysampleValC{
            constexpr Register::FieldValue<decltype(readySample)::Type,ReadysampleVal::disabled> disabled{};
            constexpr Register::FieldValue<decltype(readySample)::Type,ReadysampleVal::enabled> enabled{};
        }
        ///Shortcut between RADY event and STOP task.
        enum class ReadystopVal {
            disabled=0x00000000,     ///<Shortcut disabled.
            enabled=0x00000001,     ///<Shortcut enabled.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,ReadystopVal> readyStop{}; 
        namespace ReadystopValC{
            constexpr Register::FieldValue<decltype(readyStop)::Type,ReadystopVal::disabled> disabled{};
            constexpr Register::FieldValue<decltype(readyStop)::Type,ReadystopVal::enabled> enabled{};
        }
        ///Shortcut between DOWN event and STOP task.
        enum class DownstopVal {
            disabled=0x00000000,     ///<Shortcut disabled.
            enabled=0x00000001,     ///<Shortcut enabled.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,DownstopVal> downStop{}; 
        namespace DownstopValC{
            constexpr Register::FieldValue<decltype(downStop)::Type,DownstopVal::disabled> disabled{};
            constexpr Register::FieldValue<decltype(downStop)::Type,DownstopVal::enabled> enabled{};
        }
        ///Shortcut between UP event and STOP task.
        enum class UpstopVal {
            disabled=0x00000000,     ///<Shortcut disabled.
            enabled=0x00000001,     ///<Shortcut enabled.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,UpstopVal> upStop{}; 
        namespace UpstopValC{
            constexpr Register::FieldValue<decltype(upStop)::Type,UpstopVal::disabled> disabled{};
            constexpr Register::FieldValue<decltype(upStop)::Type,UpstopVal::enabled> enabled{};
        }
        ///Shortcut between CROSS event and STOP task.
        enum class CrossstopVal {
            disabled=0x00000000,     ///<Shortcut disabled.
            enabled=0x00000001,     ///<Shortcut enabled.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(4,4),Register::ReadWriteAccess,CrossstopVal> crossStop{}; 
        namespace CrossstopValC{
            constexpr Register::FieldValue<decltype(crossStop)::Type,CrossstopVal::disabled> disabled{};
            constexpr Register::FieldValue<decltype(crossStop)::Type,CrossstopVal::enabled> enabled{};
        }
    }
    namespace LpcompIntenset{    ///<Interrupt enable set register.
        using Addr = Register::Address<0x40013304,0xfffffff0,0x00000000,unsigned>;
        ///Enable interrupt on READY event.
        enum class ReadyVal {
            disabled=0x00000000,     ///<Interrupt disabled.
            enabled=0x00000001,     ///<Interrupt enabled.
            set=0x00000001,     ///<Enable interrupt on write.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,ReadyVal> ready{}; 
        namespace ReadyValC{
            constexpr Register::FieldValue<decltype(ready)::Type,ReadyVal::disabled> disabled{};
            constexpr Register::FieldValue<decltype(ready)::Type,ReadyVal::enabled> enabled{};
            constexpr Register::FieldValue<decltype(ready)::Type,ReadyVal::set> set{};
        }
        ///Enable interrupt on DOWN event.
        enum class DownVal {
            disabled=0x00000000,     ///<Interrupt disabled.
            enabled=0x00000001,     ///<Interrupt enabled.
            set=0x00000001,     ///<Enable interrupt on write.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,DownVal> down{}; 
        namespace DownValC{
            constexpr Register::FieldValue<decltype(down)::Type,DownVal::disabled> disabled{};
            constexpr Register::FieldValue<decltype(down)::Type,DownVal::enabled> enabled{};
            constexpr Register::FieldValue<decltype(down)::Type,DownVal::set> set{};
        }
        ///Enable interrupt on UP event.
        enum class UpVal {
            disabled=0x00000000,     ///<Interrupt disabled.
            enabled=0x00000001,     ///<Interrupt enabled.
            set=0x00000001,     ///<Enable interrupt on write.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,UpVal> up{}; 
        namespace UpValC{
            constexpr Register::FieldValue<decltype(up)::Type,UpVal::disabled> disabled{};
            constexpr Register::FieldValue<decltype(up)::Type,UpVal::enabled> enabled{};
            constexpr Register::FieldValue<decltype(up)::Type,UpVal::set> set{};
        }
        ///Enable interrupt on CROSS event.
        enum class CrossVal {
            disabled=0x00000000,     ///<Interrupt disabled.
            enabled=0x00000001,     ///<Interrupt enabled.
            set=0x00000001,     ///<Enable interrupt on write.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,CrossVal> cross{}; 
        namespace CrossValC{
            constexpr Register::FieldValue<decltype(cross)::Type,CrossVal::disabled> disabled{};
            constexpr Register::FieldValue<decltype(cross)::Type,CrossVal::enabled> enabled{};
            constexpr Register::FieldValue<decltype(cross)::Type,CrossVal::set> set{};
        }
    }
    namespace LpcompIntenclr{    ///<Interrupt enable clear register.
        using Addr = Register::Address<0x40013308,0xfffffff0,0x00000000,unsigned>;
        ///Disable interrupt on READY event.
        enum class ReadyVal {
            disabled=0x00000000,     ///<Interrupt disabled.
            enabled=0x00000001,     ///<Interrupt enabled.
            clear=0x00000001,     ///<Disable interrupt on write.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,ReadyVal> ready{}; 
        namespace ReadyValC{
            constexpr Register::FieldValue<decltype(ready)::Type,ReadyVal::disabled> disabled{};
            constexpr Register::FieldValue<decltype(ready)::Type,ReadyVal::enabled> enabled{};
            constexpr Register::FieldValue<decltype(ready)::Type,ReadyVal::clear> clear{};
        }
        ///Disable interrupt on DOWN event.
        enum class DownVal {
            disabled=0x00000000,     ///<Interrupt disabled.
            enabled=0x00000001,     ///<Interrupt enabled.
            clear=0x00000001,     ///<Disable interrupt on write.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,DownVal> down{}; 
        namespace DownValC{
            constexpr Register::FieldValue<decltype(down)::Type,DownVal::disabled> disabled{};
            constexpr Register::FieldValue<decltype(down)::Type,DownVal::enabled> enabled{};
            constexpr Register::FieldValue<decltype(down)::Type,DownVal::clear> clear{};
        }
        ///Disable interrupt on UP event.
        enum class UpVal {
            disabled=0x00000000,     ///<Interrupt disabled.
            enabled=0x00000001,     ///<Interrupt enabled.
            clear=0x00000001,     ///<Disable interrupt on write.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,UpVal> up{}; 
        namespace UpValC{
            constexpr Register::FieldValue<decltype(up)::Type,UpVal::disabled> disabled{};
            constexpr Register::FieldValue<decltype(up)::Type,UpVal::enabled> enabled{};
            constexpr Register::FieldValue<decltype(up)::Type,UpVal::clear> clear{};
        }
        ///Disable interrupt on CROSS event.
        enum class CrossVal {
            disabled=0x00000000,     ///<Interrupt disabled.
            enabled=0x00000001,     ///<Interrupt enabled.
            clear=0x00000001,     ///<Disable interrupt on write.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,CrossVal> cross{}; 
        namespace CrossValC{
            constexpr Register::FieldValue<decltype(cross)::Type,CrossVal::disabled> disabled{};
            constexpr Register::FieldValue<decltype(cross)::Type,CrossVal::enabled> enabled{};
            constexpr Register::FieldValue<decltype(cross)::Type,CrossVal::clear> clear{};
        }
    }
    namespace LpcompResult{    ///<Result of last compare.
        using Addr = Register::Address<0x40013400,0xfffffffe,0x00000000,unsigned>;
        ///Result of last compare. Decision point SAMPLE task.
        enum class ResultVal {
            bellow=0x00000000,     ///<Input voltage is bellow the reference threshold.
            above=0x00000001,     ///<Input voltage is above the reference threshold.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,ResultVal> result{}; 
        namespace ResultValC{
            constexpr Register::FieldValue<decltype(result)::Type,ResultVal::bellow> bellow{};
            constexpr Register::FieldValue<decltype(result)::Type,ResultVal::above> above{};
        }
    }
    namespace LpcompEnable{    ///<Enable the LPCOMP.
        using Addr = Register::Address<0x40013500,0xfffffffc,0x00000000,unsigned>;
        ///Enable or disable LPCOMP.
        enum class EnableVal {
            disabled=0x00000000,     ///<Disabled LPCOMP.
            enabled=0x00000001,     ///<Enable LPCOMP.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,0),Register::ReadWriteAccess,EnableVal> enable{}; 
        namespace EnableValC{
            constexpr Register::FieldValue<decltype(enable)::Type,EnableVal::disabled> disabled{};
            constexpr Register::FieldValue<decltype(enable)::Type,EnableVal::enabled> enabled{};
        }
    }
    namespace LpcompPsel{    ///<Input pin select.
        using Addr = Register::Address<0x40013504,0xfffffff8,0x00000000,unsigned>;
        ///Analog input pin select.
        enum class PselVal {
            analoginput0=0x00000000,     ///<Use analog input 0 as analog input.
            analoginput1=0x00000001,     ///<Use analog input 1 as analog input.
            analoginput2=0x00000002,     ///<Use analog input 2 as analog input.
            analoginput3=0x00000003,     ///<Use analog input 3 as analog input.
            analoginput4=0x00000004,     ///<Use analog input 4 as analog input.
            analoginput5=0x00000005,     ///<Use analog input 5 as analog input.
            analoginput6=0x00000006,     ///<Use analog input 6 as analog input.
            analoginput7=0x00000007,     ///<Use analog input 7 as analog input.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,0),Register::ReadWriteAccess,PselVal> psel{}; 
        namespace PselValC{
            constexpr Register::FieldValue<decltype(psel)::Type,PselVal::analoginput0> analoginput0{};
            constexpr Register::FieldValue<decltype(psel)::Type,PselVal::analoginput1> analoginput1{};
            constexpr Register::FieldValue<decltype(psel)::Type,PselVal::analoginput2> analoginput2{};
            constexpr Register::FieldValue<decltype(psel)::Type,PselVal::analoginput3> analoginput3{};
            constexpr Register::FieldValue<decltype(psel)::Type,PselVal::analoginput4> analoginput4{};
            constexpr Register::FieldValue<decltype(psel)::Type,PselVal::analoginput5> analoginput5{};
            constexpr Register::FieldValue<decltype(psel)::Type,PselVal::analoginput6> analoginput6{};
            constexpr Register::FieldValue<decltype(psel)::Type,PselVal::analoginput7> analoginput7{};
        }
    }
    namespace LpcompRefsel{    ///<Reference select.
        using Addr = Register::Address<0x40013508,0xfffffff8,0x00000000,unsigned>;
        ///Reference select.
        enum class RefselVal {
            supplyoneeighthprescaling=0x00000000,     ///<Use supply with a 1/8 prescaler as reference.
            supplytwoeighthsprescaling=0x00000001,     ///<Use supply with a 2/8 prescaler as reference.
            supplythreeeighthsprescaling=0x00000002,     ///<Use supply with a 3/8 prescaler as reference.
            supplyfoureighthsprescaling=0x00000003,     ///<Use supply with a 4/8 prescaler as reference.
            supplyfiveeighthsprescaling=0x00000004,     ///<Use supply with a 5/8 prescaler as reference.
            supplysixeighthsprescaling=0x00000005,     ///<Use supply with a 6/8 prescaler as reference.
            supplyseveneighthsprescaling=0x00000006,     ///<Use supply with a 7/8 prescaler as reference.
            aref=0x00000007,     ///<Use external analog reference as reference.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,0),Register::ReadWriteAccess,RefselVal> refsel{}; 
        namespace RefselValC{
            constexpr Register::FieldValue<decltype(refsel)::Type,RefselVal::supplyoneeighthprescaling> supplyoneeighthprescaling{};
            constexpr Register::FieldValue<decltype(refsel)::Type,RefselVal::supplytwoeighthsprescaling> supplytwoeighthsprescaling{};
            constexpr Register::FieldValue<decltype(refsel)::Type,RefselVal::supplythreeeighthsprescaling> supplythreeeighthsprescaling{};
            constexpr Register::FieldValue<decltype(refsel)::Type,RefselVal::supplyfoureighthsprescaling> supplyfoureighthsprescaling{};
            constexpr Register::FieldValue<decltype(refsel)::Type,RefselVal::supplyfiveeighthsprescaling> supplyfiveeighthsprescaling{};
            constexpr Register::FieldValue<decltype(refsel)::Type,RefselVal::supplysixeighthsprescaling> supplysixeighthsprescaling{};
            constexpr Register::FieldValue<decltype(refsel)::Type,RefselVal::supplyseveneighthsprescaling> supplyseveneighthsprescaling{};
            constexpr Register::FieldValue<decltype(refsel)::Type,RefselVal::aref> aref{};
        }
    }
    namespace LpcompExtrefsel{    ///<External reference select.
        using Addr = Register::Address<0x4001350c,0xfffffffe,0x00000000,unsigned>;
        ///External analog reference pin selection.
        enum class ExtrefselVal {
            analogreference0=0x00000000,     ///<Use analog reference 0 as reference.
            analogreference1=0x00000001,     ///<Use analog reference 1 as reference.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,ExtrefselVal> extrefsel{}; 
        namespace ExtrefselValC{
            constexpr Register::FieldValue<decltype(extrefsel)::Type,ExtrefselVal::analogreference0> analogreference0{};
            constexpr Register::FieldValue<decltype(extrefsel)::Type,ExtrefselVal::analogreference1> analogreference1{};
        }
    }
    namespace LpcompAnadetect{    ///<Analog detect configuration.
        using Addr = Register::Address<0x40013520,0xfffffffc,0x00000000,unsigned>;
        ///Analog detect configuration.
        enum class AnadetectVal {
            cross=0x00000000,     ///<Generate ANADETEC on crossing, both upwards and downwards crossing.
            up=0x00000001,     ///<Generate ANADETEC on upwards crossing only.
            down=0x00000002,     ///<Generate ANADETEC on downwards crossing only.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,0),Register::ReadWriteAccess,AnadetectVal> anadetect{}; 
        namespace AnadetectValC{
            constexpr Register::FieldValue<decltype(anadetect)::Type,AnadetectVal::cross> cross{};
            constexpr Register::FieldValue<decltype(anadetect)::Type,AnadetectVal::up> up{};
            constexpr Register::FieldValue<decltype(anadetect)::Type,AnadetectVal::down> down{};
        }
    }
    namespace LpcompPower{    ///<Peripheral power control.
        using Addr = Register::Address<0x40013ffc,0xfffffffe,0x00000000,unsigned>;
        ///Peripheral power control.
        enum class PowerVal {
            disabled=0x00000000,     ///<Module power disabled.
            enabled=0x00000001,     ///<Module power enabled.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,PowerVal> power{}; 
        namespace PowerValC{
            constexpr Register::FieldValue<decltype(power)::Type,PowerVal::disabled> disabled{};
            constexpr Register::FieldValue<decltype(power)::Type,PowerVal::enabled> enabled{};
        }
    }
}
