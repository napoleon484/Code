#include "stdafx.h"
#include "mockgrue.h"


MockGrue::MockGrue(void)
{

}

MockGrue::~MockGrue(void)
{
}
													// Stop thread if necessary

int	MockGrue::Run(int,int)
{
	return 0;
}

int MockGrue::Stop(void)
{
	return 0;
}
void MockGrue::Reset(void)
{
	return;
}

int MockGrue::GetCommand(void)
{
	return 0;
}

void MockGrue::Wait(int)
{
	return;
}

int MockGrue::GetErr(void)
{
	return 0;
}

void MockGrue::ClearErr(void)
{
	return;
}
int	MockGrue::LoadTrajFile(char *)
{
	return 0;
}
int	MockGrue::SetTrajBuffer(float *[3], long)
{
	return 0;
}
int MockGrue::GetTrajBuffer(float *[3], long *)
{
	return 0;
}
int	MockGrue::SetTrajMode(int)
{
	return 0;
}

int	MockGrue::GetTrajMode(void)
{
	return 0;
}

int	MockGrue::LoadCompFile(char *)
{
	return 0;
}

int	MockGrue::SetComp(struct CompParamdef comp)
{
	return 0;
}
struct CompParamdef 	GetComp(void)
{
	return CompParamdef();
}

int MockGrue::OpenSensorFile(char *)
{
	return 0;
}

int	MockGrue::CloseSensorFile(void)
{
	return 0;
}
int	MockGrue::GetSensor(float sensors[5])
{
	sensors[0] = 1;
	sensors[1] = 2;
	sensors[2] = 3;
	sensors[3] = 4;
	sensors[4] = 5;
	return 0;
}
int	MockGrue::GetScale(float [5])
{
	return 0;
}
int	MockGrue::SetScale(float [5])
{
	return 0;
}