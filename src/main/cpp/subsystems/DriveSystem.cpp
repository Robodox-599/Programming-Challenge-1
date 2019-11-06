/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/DriveSystem.h"

DriveSystem::DriveSystem() : Subsystem("DriveSystem"), frontLeftMotor(1), backLeftMotor(2), frontRightMotor(3), frontLeftMotor(4)
{
  frontLeftMotor.SetInverted(true);
  backLeftMotor.SetInverted(true);
  frontRightMotor.SetInverted(false);
  backRightMotor.SetInverted(false);

  backLeftMotor.SetSensorPhase(false);
  backRightMotor.SetSensorPhase(true);
  }

void DriveSystem::InitDefaultCommand() {
  
  
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());

// Put methods for controlling this subsystem
// here. Call these from Commands.

void DriveSystem::PowerDrive(double axis)
{
  float power;
  if(axis > 0)
  {
    power = -0.1;
  }
  else if(axis < 0)
  {
    power = 0.1;
  }
  else
  {
    power = 0;
  }
  
  frontLeftMotor.Set(ControlMode::PercentOutput, power);
  rearLeftMotor.Set(ControlMode::PercentOutput, power);
  frontRightMotor.Set(ControlMode::PercentOutput, power);
  rearRightMotor.Set(ControlMode::PercentOutput, power);
}