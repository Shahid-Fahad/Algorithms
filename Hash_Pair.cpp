template <class T>
static void hash_combine(size_t& seed,const T& v) {
     seed^=v+0x9e3779b9+(seed<<6)+(seed>>2);
}
namespace std {
    // Hash pair.
    template<typename T,typename U>
    struct hash<pair<T,U>> {
        inline size_t operator()(const pair<T,U>& p) const {
            size_t hash = 0;
            hash_combine(hash,p.first);
            hash_combine(hash,p.second);
            return hash;
        }
    };
    // Hash vector.
    template<typename T>
    struct hash<vector<T>> {
        inline size_t operator()(const vector<T>& v) const {
            size_t hash = 0;
            for(const T &val:v)
                hash_combine(hash,val);
            return hash;
        }
    };
    // Hash array.
    template<typename T>
    struct hash<array<T,2>> {
        inline size_t operator()(const array<T,2>& v) const {
            size_t hash = 0;
            for(const T &val:v)
                hash_combine(hash,val);
            return hash;
        }
    };
}