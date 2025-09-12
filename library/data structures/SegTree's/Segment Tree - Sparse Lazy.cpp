/*
Sparse Lazy Segment Tree
Status: Not tested yet
start -> segtree(minv,maxv) - (minv,maxv) = node 1 interval
update range "l,r" with "val" -> update(l,r,val);
query on range l,r -> query(l,r)
*/

struct segtree {
    vector</* type */> tr;
    vector</* type lazy */> lz;
    vector<int> lc,rc;
    int cntno, minv, maxv;

    segtree(int minv_, int maxv_) {
        minv = minv_;
        maxv = maxv_;
        cntno = 1;
        tr.assign(2,/* neutral value */);
        lz.assign(2,/* neutral value lazy */);
        lc.assign(2,0);
        rc.assign(2,0);
    }

    /* type */ mergeseg(/* type */ valL, /* type */ valR) {
        
        /* return merge of valL and valR */
    }

    void flush(int no, int l, int r) {
        if(no == 0 or lz[no] == /* neutral value lazy */) return;

        tr[no] = /* adds lz[no] to tr[no] */

        if(l != r) {
            if(lc[no] == 0) {
                lc[no] = ++cntno;
                tr.pb(/* neutral value */);
                lz.pb(/* neutral value lazy */);
                lc.pb(0);
                rc.pb(0);
            }
            if(rc[no] == 0) {
                rc[no] = ++cntno;
                tr.pb(/* neutral value */);
                lz.pb(/* neutral value lazy */);
                lc.pb(0);
                rc.pb(0);
            }

            lz[lc[no]] = /* adds lz[no] to lz[lc[no]] */
            lz[rc[no]] = /* adds lz[no] to lz[rc[no]] */
        }

        lz[no] = /* neutral value lazy */;
    }

    int upd(int no, int l, int r, int ll, int rr, /* type lazy */ val) {
        flush(no,l,r);
        if(l > rr or r < ll) return no;

        if(no == 0) {
            no = ++cntno;
            tr.pb(/* neutral value */);
            lz.pb(/* neutral value lazy */);
            lc.pb(0);
            rc.pb(0);
        }
        
        if(l >= ll and r <= rr) {
            lz[no] = val;
            flush(no,l,r);
            return no;
        }
        int mid=(l+r)>>1;
        
        int newlc = upd(lc[no],l,mid,ll,rr,val);
        lc[no] = newlc;
        int newrc = upd(rc[no],mid+1,r,ll,rr,val);
        rc[no] = newrc;
        
        tr[no] = mergeseg(tr[lc[no]],tr[rc[no]]);
        return no;
    }

    /* type */ qry(int no, int l, int r, int ll, int rr) {
        flush(no,l,r);
        if(no == 0 or l > rr or r < ll) return /* neutral value */;
        if(l >= ll and r <= rr) return tr[no];
        int mid=(l+r)>>1;
        return mergeseg(qry(lc[no],l,mid,ll,rr),qry(rc[no],mid+1,r,ll,rr));
    }

    void update(int l, int r, /* type */ val) {
        upd(1,minv,maxv,l,r,val);
    }

    /* type */ query(int l, int r) {
        return qry(1,minv,maxv,l,r);
    }
};
