/**
 * \file WiMaxError.h
 * Defines the WiMaxError type use to report errors from WiMax common API.
 * Version 1.2.1 November 2 2007
 */


/// Errors codes returned by the APIs.
/// \note Insert new error codes between WIMAX_API_RET_FIRST_COMMON_ERROR and WIMAX_API_RET_LAST_COMMON_ERROR for common error code
typedef enum _WIMAX_API_RET
{
	WIMAX_API_RET_FIRST_COMMON_ERROR = 0,
	/// No errors
	WIMAX_API_RET_SUCCESS,	
	/// Fail to obtain results
	WIMAX_API_RET_FAILED,	
	/// Buffer size pass in parameter is too small.
	WIMAX_API_RET_BUFFER_SIZE_TOO_SMALL,	
	/// Invalid privileges to execute the command
	WIMAX_API_RET_PERMISSON_DENIED,	
	/// Device specified is invalid.
	WIMAX_API_RET_INVALID_DEVICE,	
	/// Invalid Parameter Passed
    WIMAX_API_RET_INVALID_PARAMETER,
	/// Cannot perform the command mobile connection.
	WIMAX_API_RET_ALREADY_CONNECTED,
    /// Link is not connected, cannot obtain result.
	WIMAX_API_RET_LINK_NOT_CONNECTED,
	/// Connection to the network is prohibited
	WIMAX_API_RET_NETWORK_PROHIBITED,
	/// Device specified is missing because of just being removed!
	WIMAX_API_RET_DEVICE_MISSING,
	/// Profile specified is invalid.
	WIMAX_API_RET_INVALID_PROFILE,	
	/// Connection to a roaming network is not allowed.
	WIMAX_API_RET_ROAMING_NOT_ALLOWED,	
	/// Connection is already in progress
	WIMAX_API_RET_CONNECTION_IN_PROGRESS,
	/// Function not implemented
	WIMAX_API_RET_NOT_IMPLEMENTED,
	
	/// last error code
	WIMAX_API_RET_LAST_COMMON_ERROR							
} WIMAX_API_RET;
