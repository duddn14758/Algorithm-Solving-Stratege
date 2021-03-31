#define MAX_N 5
#define MAX_TAG_LEN 4
#define MAX_NAME 50007
#define MAX_NAME_LEN 8
#define MAX_TAGS 1007
 
typedef unsigned long long ll;
 
ll strcode(const char *str)
{
    ll temp = 0;
 
    for (register int i = 0; str[i] != '\0'; i++)
    {
        temp = (temp << 6) + str[i] - 'A' + 1;
    }
    return temp;
}
 
char* llcode(ll temp, char *str)
{
     
    ll temp2 = temp;
    char tchar = (char)(temp2 & 63);
    register int i;
    for (i = 0; tchar != 0; i++)
    {
        str[i] = tchar + 'A' - 1;
        temp2 = (temp2 >> 6);
        tchar = (char)(temp2 & 63);
    }
    str[i] = '\0';
    temp2 = temp;
    tchar = (char)(temp2 & 63);
    for (; i!=0; i--)
    {
        str[i-1] = tchar + 'A' - 1;
        temp2 = (temp2 >> 6);
        tchar = (char)(temp2 & 63);
    }
    return str;
}  
 
struct book {
    ll name;
    int section;
    int del;
    int count_book;
};
 
struct hashname {
    ll key;
    int item_id;
};
 
struct hashtag {
    ll key;
    int items[MAX_NAME];
    int size;
};
 
book item_arr[MAX_NAME];
int gidx = 0;
int count_book = 0;
hashname name_hash[MAX_NAME];
hashtag tags_hash[MAX_TAGS];

unsigned long hash(ll strkey, int max) {
    unsigned long hash = 5381;
    int c;
        hash = ((strkey + hash)) % max;
    return hash % max;
}
 
int find_name(ll lkey) {
    unsigned long h = hash(lkey, MAX_NAME);
    int cnt = MAX_NAME;
    while (name_hash[h].key != 0 && cnt--) {
        if (name_hash[h].key == lkey) {
            break;
        }
        h = (h + 1) % MAX_NAME;
    }
    return h;
}
 
hashtag* find_tag(ll lkey) {
    unsigned long h = hash(lkey, MAX_TAGS);

    int cnt = MAX_TAGS;

    while (tags_hash[h].key != 0 && cnt--) {
        if (tags_hash[h].key == lkey) {
            break;
        }

        h = (h + 1) % MAX_TAGS;
    }
    return &tags_hash[h];
}
 
void init(int M) {
    for (register int i = 0; i < MAX_NAME; i++) {
        item_arr[i].name = 0;
        name_hash[i].key = 0;
    }
 
    for (register int i = 0; i < MAX_TAGS; i++) {
        tags_hash[i].key = 0;
        tags_hash[i].size = 0;
    }
    gidx = 0;
}
 
void add(char mName[MAX_NAME_LEN], int mTypeNum, char mTypes[MAX_N][MAX_TAG_LEN], int mSection) {
    gidx++;
    book& item = item_arr[gidx];
 
    item.name = strcode(mName);
    item.section = mSection;
    item.del = 0;
 
    unsigned long h = find_name(item.name);
    if (!name_hash[h].key)
        name_hash[h].key = item.name;
    name_hash[h].item_id = gidx;
 
    for (register int i = 0; i < mTypeNum; i++) {
        ll lkey = strcode(mTypes[i]);
        hashtag* hash = find_tag(lkey);
        if (!hash->key)
            hash->key = strcode(mTypes[i]);
 
        hash->size += 1;
        hash->items[hash->size - 1] = gidx;
    }
}
 
int moveType(char mType[MAX_TAG_LEN], int mFrom, int mTo) {
    ll lkey = strcode(mType);
    hashtag* hash = find_tag(lkey);
    if (!hash || !hash->key || !hash->size)
        return 0;
 
    int cnt = 0;
    for (register int i = 0; i < hash->size; i++) {
        book& item = item_arr[hash->items[i]];
        if (!item.del && item.section == mFrom) {
            item.section = mTo;
            cnt++;
        }
    }
    return cnt;
}
 
void moveName(char mName[MAX_NAME_LEN], int mSection) {
    ll lkey = strcode(mName);
    int id = name_hash[find_name(lkey)].item_id;
    if (id != 0)
        item_arr[id].section = mSection;
}
 
void deleteName(char mName[MAX_NAME_LEN]) {
    ll lkey = strcode(mName);
    int id = name_hash[find_name(lkey)].item_id;
    if (id != 0)
        item_arr[id].del = 1;
}

int countBook(int mTypeNum, char mTypes[MAX_N][MAX_TAG_LEN], int mSection) {
    count_book++;
    int cnt = 0;
    for (register int i = 0; i < mTypeNum; i++) {
        ll lkey = strcode(mTypes[i]);
        hashtag* hash = find_tag(lkey);

        for (register int j = 0; j < hash->size; j++) {
            book& item = item_arr[hash->items[j]];
            if (!item.del && item.count_book != count_book && item.section == mSection) {
                cnt++;
                item.count_book = count_book;
            }
        }
    }
    return cnt;
}