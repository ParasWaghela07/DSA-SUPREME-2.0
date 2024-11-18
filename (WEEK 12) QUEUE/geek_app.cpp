    public:
    queue<int>q;
    GeekApp()
    {
        //Constructor
    }
    void Gets_Notification(int timestamp)
    {
        q.push(timestamp);
    }
    int Visits_Query(int timestamp)
    {
        while(!q.empty() && q.front()<timestamp-300) q.pop();
        return q.size();
    }