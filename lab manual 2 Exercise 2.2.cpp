#include <iostream>
using namespace std;

struct Song {
    int id;
    string title, artist;
    float duration;
    Song *prev, *next;
};

class Playlist {
    Song *head, *tail, *current;

public:
    Playlist() { head = tail = current = NULL; }

    void insert(int id, string t, string a, float d) {
        Song* n = new Song{id,t,a,d,NULL,NULL};
        if (!head) head = tail = n;
        else { tail->next = n; n->prev = tail; tail = n; }
    }

    Song* search(string key) {
        for (Song* temp=head; temp; temp=temp->next)
            if (temp->title==key || temp->artist==key) return temp;
        return NULL;
    }

    void modify(string key) {
        Song* s = search(key);
        if (!s) { cout<<"Not found\n"; return; }
        cout<<"New title: "; cin>>s->title;
        cout<<"New artist: "; cin>>s->artist;
        cout<<"New duration: "; cin>>s->duration;
    }

    void display() {
        int count=0; float total=0;
        for (Song* temp=head; temp; temp=temp->next) {
            cout<<temp->id<<" "<<temp->title<<" "<<temp->artist<<" "<<temp->duration<<"min\n";
            count++; total+=temp->duration;
        }
        cout<<"Total Songs: "<<count<<"\nTotal Duration: "<<total<<" min\n";
    }

    void nextSong() {
        if (!current) current=head;
        else if (current->next) current=current->next;
        else { cout<<"Last song!\n"; return; }
        cout<<"Playing: "<<current->title<<" - "<<current->artist<<endl;
    }

    void prevSong() {
        if (!current) current=head;
        else if (current->prev) current=current->prev;
        else { cout<<"First song!\n"; return; }
        cout<<"Playing: "<<current->title<<" - "<<current->artist<<endl;
    }
};

int main() {
    Playlist p;
    p.insert(1,"SongA","Artist1",3.5);
    p.insert(2,"SongB","Artist2",4.0);
    p.insert(3,"SongC","Artist3",2.8);

    p.display();
    p.nextSong();
    p.nextSong();
    p.prevSong();
    p.modify("SongC");
    p.display();
}