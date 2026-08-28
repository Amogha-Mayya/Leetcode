class BrowserHistory {
public:
    list<string>dll;
    list<string>::iterator curr;
    BrowserHistory(string homepage) {
        dll.push_back(homepage);
        curr = dll.begin();
    }
    
    void visit(string url) {
        auto it = curr;
        it++;
        dll.erase(it,dll.end());

        dll.push_back(url);
        curr = --dll.end();
    }
    
    string back(int steps) {
        while (steps-- && curr != dll.begin()) {
            curr--;
        }
        return *curr;
    }
    
    string forward(int steps) {
        while (steps-- && curr != (--dll.end())) {
            curr++;
        }
        return *curr;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */