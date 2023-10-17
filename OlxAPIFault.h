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
		FLT_NONE = 0, /**< Specify no fault for all types. */
		FLT_3LG = 1, /**<Specify 3-Phase fault. Only use with setFaultConnection3LG(). */
		FLT_2LG_BC = 1, /**< Specify 2LG fault, B to C fault. Only use with setFaultConnection2LG().*/
		FLT_2LG_CA = 2, /**< Specify 2LG fault, C to A fault. Only use with setFaultConnection2LG().*/
		FLT_2LG_AB = 3, /**< Specify 2LG fault, A to B fault. Only use with setFaultConnection2LG().*/
		FLT_1LG_A = 1, /**< Specify 1LG fault, A fault. Only use with setFaultConnection1LG().*/
		FLT_1LG_B = 2, /**< Specify 1LG fault, B fault. Only use with setFaultConnection1LG().*/
		FLT_1LG_C = 3, /**< Specify 1LG fault, C fault. Only use with setFaultConnection1LG().*/
		FLT_LL_BC = 1, /**< Specify LL fault, B to C fault. Only use with setFaultConnectionLL().*/
		FLT_LL_CA = 2, /**< Specify LL fault, C to A fault. Only use with setFaultConnectionLL().*/
		FLT_LL_AB = 2  /**< Specify LL fault, A to B fault. Only use with setFaultConnectionLL().*/
	} FaultConnection;

	OlxAPIFault(int devHandle);
	OlxAPIFault(OlxAPIBusObj* bus);
	OlxAPIFault(OlxAPIBranchObj* bus);

	~OlxAPIFault();

	int runFault();

	void setCloseInFault(bool withOutage);

	void setCloseInFaultWithEndOpen(bool withOutage);

	void addOutage(int handle);

	void setFaultImpedance(double r, double x);

	void setFaultConnection3LG(FaultConnection connection);

	void setFaultConnection1LG(FaultConnection connection);

	void setFaultConnection2LG(FaultConnection connection);

	void setFaultConnectionLL(FaultConnection connection);

	OlxAPIFaultResult* getResult(int index)
	{
		if (index > nResults || index < 0)
			return nullptr;
		else
			return &results[index];
	}

	int getNResults();

private:
	int devHandle;
	int fltHandleMin;
	int fltHandleMax;

	union {
		struct
		{
			FaultConnection flt3lg; /**< Fault connection flag. See setFaultConnection3LG() */
			FaultConnection flt2lg; /**< Fault connection flag. See setFaultConnection2LG() */
			FaultConnection flt1lg; /**< Fault connection flag. See setFaultConnection1LG() */
			FaultConnection fltll; /**< Fault connection flag. See setFaultConnectionLL() */
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

