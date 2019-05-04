// This is the text editor interface.
// Anything you type or change here will be seen by the other person in real time.

#include<iostream>

using namespace std;

struct linklist {
    int min;
    int max;
    struct linklist *next;
};

typedef struct linklist link;

link* head=NULL;

link *create_node (int min, int max) {
    link *nw = new link;
    nw->min = min;
    nw->max = max;
    nw->next=NULL;
    return nw;
}

void add_node(link *temp, link *tempnext, int start, int end) {
    link *nw = create_node(start, end);
    temp->next= nw;
    nw->next=tempnext;
}

void addrange(int start, int end) {
    if (end < start) {
        int temp = start;
        start = end;
        end = temp;
    }

    if(head == NULL) {
        link *nw = create_node(start, end);
        head = nw;
    } else {
        link *temp = head;
        if (temp->min > start) {
            link *nw = create_node(start, end);
            nw->next = head;
            head = nw;
            return;
        }
        while (temp->next != NULL) {
            if (temp->max >= end && temp->min <= start) return;
            if (temp->next->min >= start) {
                add_node(temp, temp->next, start, end);
            }
            temp = temp->next;
        }
    }
}

int queryrange (int start, int end) {
    link *temp = head;
    while(temp!= NULL) {
        if (temp->min <= start && temp->max >= end) return 0;
    }

    return 1;
}

int max(int max1, int max2) {
    if (max1 >= max2) return max1;
    else return max2;
}

void merge_together(link *temp, link *tempnext, int min, int max) {
    temp->min = min;
    temp->max=max;
    temp->next = tempnext->next;
    free(tempnext);
}

void merge_linklist(link *head1) {
    link *temp = head1;
    while(temp->next != NULL) {
      if (temp->min == temp->next->min || (temp->min == (temp->next->min -1))) {
          merge_together(temp, temp->next, temp->min, max(temp->max, temp->next->max));
      }
    }
}

/* ----- range question ---------- */
truct Interval
{
    int start, end;
}IntervalNode;

IntervalNode * CreateIntervalNode(int start, int end) {
    IntervalNode *nw = new IntervalNode;
    nw->start = start;
    nw->end = end;
}



/* --- Merge Interval ------------*/

struct Interval
{
    int start, end;
}IntervalNode;

struct compareInterval {
    bool operator() (const IntervalNode &i1, const IntervalNode &i2) {
        return (i1.start < i2.start);
    }
};

// The main function that takes a set of intervals, merges
// overlapping intervals and prints the result
void mergeIntervals(Interval arr[], int n)
{
    // Test if the given set has at least one interval
    if (n <= 0)
        return;

    // Create an empty stack of intervals
    stack<Interval> s;

    // sort the intervals in increasing order of start time
    sort(arr, arr+n, compareInterval);

    // push the first interval to stack
    s.push(arr[0]);

    // Start from the next interval and merge if necessary
    for (int i = 1 ; i < n; i++)
    {
        // get interval from stack top
        Interval top = s.top();

        // if current interval is not overlapping with stack top,
        // push it to the stack
        if (top.end < arr[i].start)
            s.push(arr[i]);

        // Otherwise update the ending time of top if ending of current
        // interval is more
        else if (top.end < arr[i].end)
        {
            top.end = arr[i].end;
            s.pop();
            s.push(top);
        }
    }

    // Print contents of stack
    cout << "\n The Merged Intervals are: ";
    while (!s.empty())
    {
        Interval t = s.top();
        cout << "[" << t.start << "," << t.end << "] ";
        s.pop();
    }
    return;
}

int main (){
    addrange(1 , 3);
    addrange(1, 5);
    merge_linklist(head);
    int i = queryrange(1,5);
 //   int i = queryrange(4,6);
    if (i == 0) printf("found the range\n");
    else printf("not found the range\n");
    return 0;
}