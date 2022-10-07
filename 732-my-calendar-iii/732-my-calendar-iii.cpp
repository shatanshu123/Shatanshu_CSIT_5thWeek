class MyCalendarThree {
public:
    // Hashmap to store event and its occurrence 
    map<int,int> events;
    // Holds events that intersects
    int k;
    
    MyCalendarThree() {
        k = 1; // If there is no intersection then, k = 1
    }
    
    int book(int start, int end) {
        events[start]++;    // Inc to represent start of the event
        events[end]--;      // Decrement to represent end of an event
        
        // If the current event has no intersection,
        // Then no need to find maximum intersections
        // Simply return previously k intersection events
        if(events[start] == 1 && events.lower_bound(start)->first == end)
            return k;
        
        // Otherwise find active intersecting events
        int active = 0;
        map<int,int>::iterator it = events.begin();
        
        // Iterate over all events before the ending of current event
        while(it->first != end){
            active += it->second;
            k = max(k,active); // Update k, if more active intersecting events
            it++;
        }
        
        return k;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */