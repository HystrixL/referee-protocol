#pragma once

namespace rp {
enum class RobotId : unsigned char {
    RedHero = 1,
    RedEngineer = 2,
    RedStandard3 = 3,
    RedStandard4 = 4,
    RedStandard5 = 5,
    RedAerial = 6,
    RedSentry = 7,
    RedDart = 8,
    RedRadar = 9,
    RedOutpost = 10,
    RedBase = 11,
    BlueHero = 101,
    BlueEngineer = 102,
    BlueStandard3 = 103,
    BlueStandard4 = 104,
    BlueStandard5 = 105,
    BlueAerial = 106,
    BlueSentry = 107,
    BlueDart = 108,
    BlueRadar = 109,
    BlueOutpost = 110,
    BlueBase = 111,
};

enum class ClientId : unsigned short {
    RedHero = 0x0101,
    RedEngineer = 0x0102,
    RedStandard3 = 0x0103,
    RedStandard4 = 0x0104,
    RedStandard5 = 0x0105,
    RedAerial = 0x0106,
    BlueHero = 0x0165,
    BlueEngineer = 0x0166,
    BlueStandard3 = 0x0167,
    BlueStandard4 = 0x0168,
    BlueStandard5 = 0x0169,
    BlueAerial = 0x016A,
    RefereeSystemServer = 0x8080
};
}  // namespace rp