#pragma once

#include "olxapi/include/olxapi.h"
#include "OlxAPIBusObj.h"
#include "OlxAPIBranchObj.h"
#include "OlxAPIFaultResult.h"

class OlxAPIFault
{
public:
	/** Fault Connection Type
	* This is used when configuring fault options.
	*/
	typedef enum FaultConnection
	{
		FLT_3LG = 0, /**< Specify 3-Phase fault */
		FLT_2LG_BC = 1, /**< Specify 2LG fault, B to C fault */
		FLT_2LG_CA = 2, /**< Specify 2LG fault, C to A fault */
		FLT_2LG_AB = 3, /**< Specify 2LG fault, A to B fault */
		FLT_1LG_A = 4, /**< Specify 1LG fault, A fault */
		FLT_1LG_B = 5, /**< Specify 1LG fault, B fault */
		FLT_1LG_C = 6, /**< Specify 1LG fault, C fault */
		FLT_LL_BC = 7, /**< Specify LL fault, B to C fault */
		FLT_LL_CA = 8, /**< Specify LL fault, C to A fault */
		FLT_LL_AB = 9  /**< Specify LL fault, A to B fault */
	} FaultConnection;

	typedef enum FaultType
	{
		FLT_CLOSE_IN = 0, /**< Specify Close-In fault */
		FLT_CLOSE_IN_WO = 1, /**< Specify Close-In fault with outages */
		FLT_CLOSE_IN_EO = 2, /**< Specify Close-In, End-Open fault */
		FLT_CLOSE_IN_EO_WO = 3, /**< Specify Close-In, End-Open fault with outages */
		FLT_INT = 4, /**< Specify Intermediate fault */
		FLT_INT_WO = 5, /**< Specify Intermediate fault with outages */
		FLT_INT_EO = 6, /**< Specify Intermediate, End-Open fault */
		FLT_INT_EO_WO = 7, /**< Specify Intermediate, End-Open fault with outages */
	} FaultType;

	OlxAPIFault(int devHandle);
	OlxAPIFault(OlxAPIBusObj* bus);
	OlxAPIFault(OlxAPIBranchObj* bus);
	OlxAPIFault(OlxAPIObj* bus);

	~OlxAPIFault();

	void setFaultConnection(FaultConnection connection);

	void setFaultType(FaultType type, double intPct = 0);

	int runFault();

	void addOutage(int handle);

	void setFaultImpedance(double r, double x);

	OlxAPIFaultResult* getResult(int index);

	int getNResults();

private:
	int devHandle;
	int fltHandleMin;
	int fltHandleMax;

	FaultConnection fltConnection;

	union {
		struct
		{
			int flt3lg; /**< Fault connection flag */
			int flt2lg; /**< Fault connection flag */
			int flt1lg; /**< Fault connection flag */
			int fltll; /**< Fault connection flag */
		};
		int _fltConns[4];
	} faultConnections;

	struct
	{
		double r; /**< Fault resistance in ohms. */
		double x; /**< Fault reactance in ohms. */
	} faultResistance;

	union {
		struct
		{
			double closeIn; /**< 0 - reset, 1 - set */
			double closeInWOutage; /**< 0 - reset, 1 - set */
			double closeInWEndOpen; /**< 0 - reset, 1 - set */
			double closeInWEndOpenWOutage; /**< 0 - reset, 1 - set */
			double remoteBus; /**< 0 - reset, 1 - set */
			double remoteBusWOutage; /**< 0 - reset, 1 - set */
			double lineEnd; /**< 0 - reset, 1 - set */
			double lineEndWOutage; /**< 0 - reset, 1 - set */

			/**
			* Set this value to 0 undesired, otherwise set the % to anything to 0.01 - 100.00.
			*  If an auto sequenced fault is desired, enter the step size. and set autoSeqFrom and autoSeqTo appropriately.
			*/
			double intermediate; // 0 - reset, 0.01 - 100% - set
			double intermediateWOutage; // 0 - reset, 0.01 - 100% - set
			double intermediateWEndOpen; // 0 - reset, 0.01 - 100% - set
			double intermediateWEndOpenWOutage; // 0 - reset, 0.01 - 100% - set
			/**
			* Set both autoSeqFrom = 0 and autoSeqTo = 0 to run a single point intermediate fault. Otherwise, set from and to to bounds.
			*/
			double autoSeqFrom; /**< 0 % -100 %, must be smaller than autoSeqTo */
			double autoSeqTo; /**< 0 % -100 %, must be larger than autoSeqFrom */

			double outageGrounding; /**< Outage grounding Admittance in mhos */
		};
		double _fltOpts[15];
	} faultOptions;

	int nOutages;
	int* outageList; // pointer to list of outage busses, 0 terminated

	union {
		struct
		{
			int oneAtATime;
			int twoAtATime;
			int allAtOnce;
			int breakerFailure;
		};
		int _outageOpts[4];
	} outageOptions;

	int clearPrevious; // 0 - do not clear, 1 - clear previous faults

	int nResults;
	OlxAPIFaultResult* results;
};

