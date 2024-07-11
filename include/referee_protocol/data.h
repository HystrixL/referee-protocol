#pragma once

#include <referee_protocol/id.h>

namespace rp {
template <unsigned short TCMD_ID>
struct [[gnu::packed]] IData {
    static constexpr unsigned short CMD_ID{TCMD_ID};
};

struct [[gnu::packed]] GameStatus : IData<0x0001> {
    enum class GameType : unsigned char { RMUC = 1, RMUT = 2, RMUA = 3, RMUL3v3 = 4, RMUL1v1 = 5 };
    enum class GameProgress : unsigned char {
        PreCompetition = 0,
        Preparation = 1,
        RefereeSystemInitialization_15second = 2,
        Countdown_5second = 3,
        InCompetition = 4,
        CompetitionResultCalculation = 5
    };

    GameType game_type : 4 {};
    GameProgress game_progress : 4 {};
    unsigned short stage_remain_time{};
    unsigned long long SyncTimeStamp{};
};
struct [[gnu::packed]] GameResult : IData<0x0002> {
    enum class Winner : unsigned char { Draw = 0, Red = 1, Blue = 2 };
    Winner winner{};
};

struct [[gnu::packed]] GameRobotHp : IData<0x003> {
    unsigned short Red1Hero{};
    unsigned short Red2Engineer{};
    unsigned short Red3Standard{};
    unsigned short Red4Standard{};
    unsigned short Red5Standard{};
    unsigned short Red7Sentry{};
    unsigned short RedOutpost{};
    unsigned short RedBase{};
    unsigned short Blue1Hero{};
    unsigned short Blue2Engineer{};
    unsigned short Blue3Standard{};
    unsigned short Blue4Standard{};
    unsigned short Blue5Standard{};
    unsigned short Blue7Sentry{};
    unsigned short BlueOutpost{};
    unsigned short BlueBase{};
};
struct [[gnu::packed]] EventData : IData<0x0101> {
    unsigned long event_data{};
};
struct [[gnu::packed]] ExtSupplyProjectileAction : IData<0x0102> {
    enum class SupplyProjectileStep : unsigned char { Closed = 0, Preparing = 1, Releasing = 2 };
    enum class SupplyProjectileNum : unsigned char {
        Projectiles50 = 50,
        Projectiles100 = 100,
        Projectiles150 = 150,
        Projectiles200 = 200
    };
    unsigned char reserved{};
    RobotId supply_robot_id{};
    SupplyProjectileStep supply_projectile_step{};
    SupplyProjectileNum supply_projectile_num{};
};
struct [[gnu::packed]] RefereeWarning : IData<0x0104> {
    enum class Level : unsigned char { BothYellowCard = 1, YellowCard = 2, RedCard = 3, Forfeiture = 4 };
    Level level{};
    RobotId offending_robot_id{};
    unsigned char count{};
};
struct [[gnu::packed]] DartInfo : IData<0x0105> {
    unsigned char dart_remaining_time{};
    unsigned short dart_info{};
};
struct [[gnu::packed]] RobotStatus : IData<0x0201> {
    unsigned char robot_id;
    unsigned char robot_level;
    unsigned short current_HP;
    unsigned short maximum_HP;
    unsigned short shooter_barrel_cooling_value;
    unsigned short shooter_barrel_heat_limit;
    unsigned short chassis_power_limit;
    unsigned char power_management_gimbal_output : 1;
    unsigned char power_management_chassis_output : 1;
    unsigned char power_management_shooter_output : 1;
};
struct [[gnu::packed]] PowerHeatData : IData<0x0202> {
    unsigned short chassis_voltage;
    unsigned short chassis_current;
    float chassis_power;
    unsigned short buffer_energy;
    unsigned short shooter_17mm_1_barrel_heat;
    unsigned short shooter_17mm_2_barrel_heat;
    unsigned short shooter_42mm_barrel_heat;
};
struct [[gnu::packed]] RobotPos : IData<0x0203> {
    float x;
    float y;
    float angle;
};
struct [[gnu::packed]] Buff : IData<0x0204> {
    unsigned char recovery_buff;
    unsigned char cooling_buff;
    unsigned char defence_buff;
    unsigned char vulnerability_buff;
    unsigned short attack_buff;
};
struct [[gnu::packed]] AirSupportData : IData<0x0205> {
    enum class AirforceStatus : unsigned char { Cooling = 0, CoolingCompleted = 1, Ongoing = 2 };
    AirforceStatus airforce_status;
    unsigned char time_remain;
};
struct [[gnu::packed]] HurtData : IData<0x0206> {
    enum class HPDeductionReason : unsigned char {
        ArmorModuleAttackedByProjectiles = 0,
        CriticalRefereeSystemModuleOffline = 1,
        InitialLaunchingSpeedExceedsUpperLimit = 2,
        BarrelHeatExceedsUpperLimit = 3,
        ChassisPowerConsumptionLimitExceeded = 4,
        ArmorModuleSuffersCollision = 5
    };
    unsigned char armor_id : 4;
    HPDeductionReason HP_deduction_reason : 4;
};
struct [[gnu::packed]] ShootData : IData<0x0207> {
    enum class BulletType : unsigned char { Mm17 = 1, Mm42 = 2 };
    enum class ShooterNumber : unsigned char { FirstMm17 = 1, SecondMm17 = 2, Mm42 = 3 };
    BulletType bullet_type;
    ShooterNumber shooter_number;
    unsigned int launching_frequency;
    float initial_speed;
};
struct [[gnu::packed]] ProjectileAllowance : IData<0x0208> {
    unsigned short projectile_allowance_17mm;
    unsigned short projectile_allowance_42mm;
    unsigned short remaining_gold_coin;
};
struct [[gnu::packed]] RfidStatus : IData<0x0209> {
    unsigned int rfid_status;
};
struct [[gnu::packed]] DartClientCmd : IData<0x020A> {
    enum class DartLaunchOpeningStatus : unsigned char { Opened = 0, Closed = 1, OpeningOrClosing = 2 };
    DartLaunchOpeningStatus dart_launch_opening_status;
    unsigned char reserved;
    unsigned short target_change_time;
    unsigned short latest_launch_cmd_time;
};
struct [[gnu::packed]] GroundRobotPosition : IData<0x020B> {
    float hero_x;
    float hero_y;
    float engineer_x;
    float engineer_y;
    float standard_3_x;
    float standard_3_y;
    float standard_4_x;
    float standard_4_y;
    float standard_5_x;
    float standard_5_y;
};
struct [[gnu::packed]] RadarMarkData : IData<0x020C> {
    unsigned char mark_hero_progress;
    unsigned char mark_engineer_progress;
    unsigned char mark_standard_3_progress;
    unsigned char mark_standard_4_progress;
    unsigned char mark_standard_5_progress;
    unsigned char mark_sentry_progress;
};
struct [[gnu::packed]] SentryInfo : IData<0x020D> {
    unsigned int sentry_info;
};
struct [[gnu::packed]] RadarInfo : IData<0x020E> {
    unsigned char radar_info;
};
struct [[gnu::packed]] RobotInteractionData : IData<0x0301> {};
struct [[gnu::packed]] InteractionLayerDelete : IData<0x0301> {};
struct [[gnu::packed]] InteractionFigure : IData<0x0301> {};
struct [[gnu::packed]] InteractionFigure2 : IData<0x0301> {};
struct [[gnu::packed]] InteractionFigure3 : IData<0x0301> {};
struct [[gnu::packed]] InteractionFigure4 : IData<0x0301> {};
struct [[gnu::packed]] ExtClientCustomCharacter : IData<0x0301> {};
struct [[gnu::packed]] SentryCmd : IData<0x0301> {};
struct [[gnu::packed]] RadarCmd : IData<0x0301> {};
}  // namespace rp