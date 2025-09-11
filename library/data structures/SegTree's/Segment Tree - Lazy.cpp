/*
Lazy Segment Tree
(Not tested yet)
minv,maxv -> Node 1 interval
start -> build(1,minv,maxv);
update range (L,R) with val -> upd(1,minv,maxv,L,R,val);
query on range L,R -> qry(1,minv,maxv,L,R);
*/

struct segtree {

    vector</* type */> tr;
    vector</* type lazy */> tr;

    segtree(int n_) {
        tr.resize(4*n_+1);
        lz.resize(4*n_+1);
    }

    /* type */ mergeseg(/* type */ valL, /* type */ valR) {

        /* return merge of valL and valR */
    }

    void flush(int no, int l, int r) {
        tr[no] = /* adds lz[no] to tr[no] */;

        if(l != r) {
            int lc=2*no,rc=2*no+1;
            lz[lc] = /* adds lz[no] to lz[lc] */;
            lz[rc]+= /* adds lz[no] to lz[rc] */;
        }

        lz[no] = /* neutral value lazy */;
    }

    void build(int no, int l, int r) {
        lz[no] = /* neutral value lazy*/;
        if(l == r) {
            tr[no] = /* inicial value */;
            return;
        }
        int lc=2*no,rc=2*no+1,mid=(l+r)>>1;
        build(lc,l,mid);
        build(rc,mid+1,r);
        tr[no] = mergeseg(tr[lc],tr[rc]);
    }

    void upd(int no, int l, int r, int ll, int rr, /* type */ val) {
        flush(no,l,r);
        if(l > rr or r < ll) return;
        if(l >= ll and r <= rr) {
            lz[no] = val;
            flush(no,l,r);
            return;
        }
        int lc=2*no,rc=2*no+1,mid=(l+r)>>1;
        upd(lc,l,mid,ll,rr,val);
        upd(rc,mid+1,r,ll,rr,val);
        tr[no] = mergeseg(tr[lc],tr[rc]);
    }

    /* type */ qry(int no, int l, int r, int ll, int rr) {
        flush(no,l,r);
        if(l > rr or r < ll) return /* neutral value */;
        if(l >= ll and r <= rr) return tr[no];
        int lc=2*no,rc=2*no+1,mid=(l+r)>>1;
        return mergeseg(qry(lc,l,mid,ll,rr),qry(rc,mid+1,r,ll,rr));
    }
};
