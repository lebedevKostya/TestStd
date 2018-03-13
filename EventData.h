#ifndef EVENTDATA
#define EVENTDATA

#include <QtCore/QBuffer>
#include <QtCore/QDateTime>
#include <QtCore/QVariant>

#include <cstdlib>
#include <cstring>

#endif // EVENTDATA


class EventData
{
private:
    QByteArray eventId_;
    QDateTime time_;
    QString message_;
    quint16 severity_;
    QString sourceName_;
    QString type_;
    QString conditionName_;
    bool activeStateId_;
    bool ackedStateId_;
    QString clientUserId_;
    QVariant value_;
    QString comment_;
    QString algorithm_;
    QString responsible_;
    QString sourceNode_;
    QDateTime transitionTime_;
    QDateTime deviceTime_;
    QString effectiveDisplayName_;


    size_t bufLen_;
    char databuf_[700];

public:

   //Setters

     inline void setEventId(QByteArray eventId)                         {eventId_ = eventId;}
     inline void setTime(QDateTime time)                                {time_ = time;}
     inline void setMessage(QString message)                            {message_ = message;}
     inline void setSeverity(quint16 severity)                          {severity_=severity;}
     inline void setSourceName(QString sourceName)                      {sourceName_ = sourceName;}
     inline void setType(QString type)                                  {type_ = type;}
     inline void setConditionName(QString conditionName)                {conditionName_ = conditionName;}
     inline void setActiveStateId(bool activeStateId)                   {activeStateId_ = activeStateId;}
     inline void setAckedStateId(bool ackedStateId)                     {ackedStateId_ = ackedStateId;}
     inline void setClientUserId(QString clientUserId)                  {clientUserId_ = clientUserId;}
     inline void setValue(QVariant value)                               {value_= value;}
     inline void setComment(QString comment)                            {comment_ =comment;}
     inline void setAlgorithm(QString algorithm)                        {algorithm_ = algorithm;}
     inline void setResponsible(QString responsible)                    {responsible_ = responsible;}
     inline void setSourceNode(QString sourceNode)                      {sourceNode_ = sourceNode;}
     inline void setTransitionTime(QDateTime transitionTime)            {transitionTime_ = transitionTime;}
     inline void setDeviceTime (QDateTime deviceTime)                   {deviceTime_ = deviceTime;}
     inline void setEffectiveDisplayName(QString effectiveDisplayName)  {effectiveDisplayName_ = effectiveDisplayName;}


    //Getters

     inline QByteArray& getEventId()                                    {return (eventId_);}
     inline QDateTime& getTime()                                        {return (time_);}
     inline QString& getMessage()                                       {return (message_);}
     inline quint16& getSeverity()                                      {return (severity_);}
     inline QString& getSourceName()                                    {return (sourceName_);}
     inline QString& getType()                                          {return (type_);}
     inline QString&  getConditionName()                                {return (conditionName_);}
     inline bool& getActiveStateId()                                    {return (activeStateId_);}
     inline bool& getAckedStateId()                                     {return (ackedStateId_);}
     inline QString& getClientUserId()                                  {return (clientUserId_);}
     inline QVariant& getValue()                                        {return (value_);}
     inline QString& getComment()                                       {return (comment_);}
     inline QString& getAlgorithm()                                     {return (algorithm_);}
     inline QString& getResponsible()                                   {return (responsible_);}
     inline QString& getSourceNode()                                    {return (sourceNode_);}
     inline QDateTime& getTransitionTime()                              {return(transitionTime_);}
     inline QDateTime& getDeviceTime()                                  {return(deviceTime_);}
     inline QString& getEffectiveDisplayName()                          {return(effectiveDisplayName_);}


     void clear()
     {
         QDateTime time;

         eventId_ = 0 ;
         time_ = time.currentDateTime();
         message_ = "";
         severity_ = 0;
         sourceName_ = "";
         type_ = "";
         conditionName_ = "";
         activeStateId_ = false;
         ackedStateId_ = false;
         clientUserId_= "";
         value_ = "";
         comment_ = "";
         algorithm_ = "";
         responsible_ = "";
         sourceNode_ = "";
         transitionTime_ =time.currentDateTime();
         deviceTime_ = time.currentDateTime();
         effectiveDisplayName_ = "";

     }

    // Default constructor
    EventData()
    {
        clear();
    }

    // Constructor from a void *
    // For use with the data returned from a bdb get
    EventData(void *buffer)
        {
            char *buf = (char *)buffer;

            eventId_ = *((QByteArray *)buf);
            bufLen_ = sizeof(QByteArray);

            time_ = *((QDateTime *)(buf + bufLen_));
            bufLen_ += sizeof(QDateTime);

            message_= buf + bufLen_;
            bufLen_ += message_.size() + 1;

            severity_ = *((quint16 *)(buf + bufLen_));
            bufLen_ += sizeof(quint16);

            sourceName_ = buf + bufLen_;
            bufLen_ += sourceName_.size() + 1;

            type_ = buf + bufLen_;
            bufLen_ += type_.size() + 1;

            conditionName_ = buf + bufLen_;
            bufLen_ += conditionName_.size() + 1;

            activeStateId_ = *((bool *)(buf + bufLen_));
            bufLen_ += sizeof(bool);

            ackedStateId_ = *((bool *)(buf + bufLen_));
            bufLen_ += sizeof(bool);

            clientUserId_ = buf + bufLen_;
            bufLen_ += clientUserId_.size() + 1;

            value_ = *((QVariant *)(buf + bufLen_));
            bufLen_ += sizeof(QVariant);

            comment_ = buf + bufLen_;
            bufLen_ += comment_.size() + 1;

            algorithm_ = buf + bufLen_;
            bufLen_ += algorithm_.size() + 1;

            responsible_ = buf + bufLen_;
            bufLen_ += responsible_.size() + 1;

            sourceNode_ = buf + bufLen_;
            bufLen_ += sourceNode_.size() + 1;

            transitionTime_ = *((QDateTime *)(buf + bufLen_));
            bufLen_ += sizeof(QDateTime);

            deviceTime_ = *((QDateTime *)(buf + bufLen_));
            bufLen_ += sizeof(QDateTime);

            effectiveDisplayName_ = buf + bufLen_;
            bufLen_ += effectiveDisplayName_.size() + 1;

        }



       // Marshalls this classes data members into a single
      // contiguous memory location for the purpose of storing
      // the data in a database.
    char * getBuffer()
    {
        // Zero out the buffer
        memset(databuf_, 0, 700);
        // Now pack the data into a single contiguous memory location
        // for storage.
        bufLen_ = 0;
        int dataLen = 0;

        dataLen = sizeof(QByteArray);
        memcpy(databuf_, &eventId_, dataLen);
        bufLen_ += dataLen;

        dataLen = sizeof(QDateTime);
        memcpy(databuf_ + bufLen_, &time_, dataLen);
        bufLen_ += dataLen;

        dataLen = sizeof(quint16);
        memcpy(databuf_ + bufLen_, &severity_, dataLen);
        bufLen_ += dataLen;

        dataLen = sizeof(bool);
        memcpy(databuf_ + bufLen_, &activeStateId_, dataLen);
        bufLen_ += dataLen;

        dataLen = sizeof(bool);
        memcpy(databuf_ + bufLen_, &ackedStateId_, dataLen);
        bufLen_ += dataLen;

        dataLen = sizeof(QVariant);
        memcpy(databuf_ + bufLen_, &value_, dataLen);
        bufLen_ += dataLen;

        dataLen = sizeof(QDateTime);
        memcpy(databuf_ + bufLen_, &transitionTime_, dataLen);
        bufLen_ += dataLen;

        dataLen = sizeof(QDateTime);
        memcpy(databuf_ + bufLen_, &deviceTime_, dataLen);
        bufLen_ += dataLen;

        packString(databuf_, message_);
        packString(databuf_, sourceName_);
        packString(databuf_, type_);
        packString(databuf_, conditionName_);
        packString(databuf_, clientUserId_);
        packString(databuf_, comment_);
        packString(databuf_, algorithm_);
        packString(databuf_, responsible_);
        packString(databuf_, sourceNode_);
        packString(databuf_, effectiveDisplayName_);

        return (databuf_);
    }

     inline size_t getBufferSize() { return (bufLen_); }

     // void show() {}    реализовать


private:

     /*
      * Utility function that appends a char * to the end of
      * the buffer.
      */
     void packString(char *buffer, QString &theString)
     {
         size_t string_size = theString.size() + 1;

         memcpy(buffer+bufLen_, theString.toStdString().c_str(), string_size);
         bufLen_ += string_size;
     }







};

