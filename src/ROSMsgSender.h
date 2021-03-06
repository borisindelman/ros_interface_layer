#ifndef ROS_MSG_SENDER
#define ROS_MSG_SENDER

#include "SynchronisedQueue.h"
#include "OSALThread.h"
//#include "RosDataHandle.h"
#include "ros/ros.h"

class RosDataHandleBase;

class RosMsgSender : public OSALThread
{
public:

	RosMsgSender();
	virtual ~RosMsgSender();

	void init();

	void setTopicName(const std::string& topic);

	void enqueue(RosDataHandleBase* rosDataHandleBasePtr);

	void send();

	virtual void run();

private:
	typedef SynchronisedQueue< RosDataHandleBase* > SyncQueue;
	SyncQueue m_queue;
	std::string m_topicName;
	// ros::Publisher m_pub;
};


#endif // ROS_MSG_SENDER
