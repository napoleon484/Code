#pragma once
#include "craneexports.h"
class MockGrue
{
public:
	MockGrue(void);
	~MockGrue(void);

	int					Run(int,int);								// Run crane
	int					Stop(void);									// Stop crane
	void				Reset(void);								// Reset crane
	int					GetCommand(void);							// Get host command
	void					Wait(int);									// Wait until the system reach a state
	int 					GetErr(void);								// Get last error code
	void					ClearErr(void);								// Clear last error code

	int					LoadTrajFile(char *);						// Load trajectory from binary file
	int					SetTrajBuffer(float *[3], long);			// Set trajectory buffer pointer
	int 					GetTrajBuffer(float *[3], long *);			// Get trajectroy buffer pointer
	int					SetTrajMode(int);							// Set trajectory mode
	int					GetTrajMode(void);							// Get trajectory mode

	int					LoadCompFile(char *);						// Load compensator parameters
	int					SetComp(struct CompParamdef comp);			// Set structure compensateur
	struct CompParamdef 	GetComp(void);								// Get structure compensateur

	int					OpenSensorFile(char *);						// Save sensor buffers to binary file
	int					CloseSensorFile(void);						// Get sensor buffers pointer
	int					GetSensor(float [5]);						// Get current sensor values
	int					GetScale(float [5]);						// Get position and angle scale factors
	int					SetScale(float [5]);						// Set position and angle scale factors
};

