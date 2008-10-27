#ifndef __job__
#define __job__

#include <wx/event.h>

extern const wxEventType wxEVT_CMD_JOB_STATUS;
extern const wxEventType wxEVT_CMD_JOB_STATUS_VOID_PTR;

/**
 * \class Job
 * \author Eran
 * \date 05/09/08
 * \file job.h
 * \brief this class defines the interface to a job used by the JobQueue
 * To use the JobQueue, you should inherit from Job, and implement the Porcess() pure virtual function
 */
class Job
{
	wxEvtHandler *m_parent;
public:
	/**
	 * @brief Construct Job object with optional parent event handler.
	 * @param parent event handler class which would like to receive notifications of progress
	 */
	Job(wxEvtHandler *parent = NULL);
	virtual ~Job();

public:
	/**
	 * @brief post string and int values to parent in a form of wxCommandEvent of type wxEVT_CMD_JOB_STATUS. the string can be accessed by using event.GetString() and the int
	 * by calling event.GetInt(). 
	 * this function has no affect if parnet is NULL
	 * @param i
	 * @param message
	 */
	void Post(int i, const wxString &message);
	/**
	 * @brief post void* to parent in a form of wxCommandEvent of type wxEVT_CMD_JOB_STATUS_VOID_PTR. the void* can be accessed by using event.GetClientData() method. 
	 * NB: User must free the void* 
	 * this function has no affect if parnet is NULL
	 * @param i integer to send to parent
	 */
	virtual void Post(void *ptr);
	/**
	 * @brief overridable Process() method
	 */
	virtual void Process() = 0;
};
#endif // __job__
