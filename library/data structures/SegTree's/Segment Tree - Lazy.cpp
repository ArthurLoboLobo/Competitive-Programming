/*
Lazy Segment Tree
Status: Tested - https://codeforces.com/edu/course/2/lesson/5/2/practice/contest/279653/problem/A
minv,maxv -> Node 1 interval
start -> build(1,minv,maxv);
update range (l,r) with val -> update(l,r,val)
query on range l,r -> query(l,r);
*/

using tseg = ll; // change: seg type
using tlazy = ll; // change: lazy type
struct segtree {
    const tseg tr0 = 0; // change: neutral value for seg
    const tlazy lz0 = 0; // change: neutral value for lazy

    int sz;
    vector<tseg> tr;
    vector<tlazy> lz;

    segtree(int n_) {
        sz = n_;
        tr = vector<tseg>(4*n_+1);
        lz = vector<tlazy>(4*n_+1);
    }

    
    tseg mergeseg(tseg valL, tseg valR) {
        return valL+valR; // change: return merge of valL and valR
    }

    void flush(int no, int l, int r) {
        if(lz[no] == lz0) return;
        tr[no]+= lz[no]; // change: add lz[no] to tr[no]

        if(l != r) {
            int lc=2*no,rc=2*no+1;
            lz[lc]+= lz[no]; // change: add lz[no] to lz[lc]
            lz[rc]+= lz[no]; // change: add lz[no] to lz[rc]
        }

        lz[no] = lz0;
    }

    void build(int no, int l, int r) {
        lz[no] = lz0;
        if(l == r) {
            tr[no] = tr0; // change: initial value
            return;
        }
        int lc=2*no,rc=2*no+1,mid=(l+r)>>1;
        build(lc,l,mid);
        build(rc,mid+1,r);
        tr[no] = mergeseg(tr[lc],tr[rc]);
    }

    void upd(int no, int l, int r, int L, int R, tlazy val) {
        flush(no,l,r);
        if(l > R or r < L) return;
        if(l >= L and r <= R) {
            lz[no] = val;
            flush(no,l,r);
            return;
        }
        int lc=2*no,rc=2*no+1,mid=(l+r)>>1;
        upd(lc,l,mid,L,R,val);
        upd(rc,mid+1,r,L,R,val);
        tr[no] = mergeseg(tr[lc],tr[rc]);
    }

    tseg qry(int no, int l, int r, int L, int R) {
        flush(no,l,r);
        if(l > R or r < L) return tr0;
        if(l >= L and r <= R) return tr[no];
        int lc=2*no,rc=2*no+1,mid=(l+r)>>1;
        return mergeseg(qry(lc,l,mid,L,R),qry(rc,mid+1,r,L,R));
    }

    void update(int l, int r, tlazy val) {
        if(l > r) return;
        upd(1,1,sz,l,r,val); // change: (1,sz) to range of node 1
    }

    tseg query(int l, int r) {
        return qry(1,1,sz,l,r); // change: (1,sz) to range of node 1
    }

};
