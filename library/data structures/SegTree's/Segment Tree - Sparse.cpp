/*
Sparse Segment Tree
Status: Tested - https://cses.fi/problemset/task/1144/
start -> segtree(minv,maxv) - (minv,maxv) = node 1 interval
update position "pos" with "val" -> update(pos,val);
query on range l,r -> query(l,r)
*/

struct segtree {
    vector</* type */> tr;
    vector<int> lc,rc;
    int cntno, minv, maxv;

    segtree(int minv_, int maxv_) {
        minv = minv_;
        maxv = maxv_;
        cntno = 1;
        tr.assign(2,/* neutral value */);
        lc.assign(2,0);
        rc.assign(2,0);
    }

    /* type */ mergeseg(/* type */ valL, /* type */ valR) {
        
        /* return merge of valL and valR */
    }

    int upd(int no, int l, int r, int pos, /* type */ val) {
        if(l > pos or r < pos) return no;

        if(no == 0) {
            no = ++cntno;
            tr.pb(/* neutral value */);
            lc.pb(0);
            rc.pb(0);
        }
        
        if(l == r) {
            tr[no] = /* adds val to tr[no] */;
            return no;
        }
        int mid=(l+r)>>1;
        
        int newlc = upd(lc[no],l,mid,pos,val);
        lc[no] = newlc;
        int newrc = upd(rc[no],mid+1,r,pos,val);
        rc[no] = newrc;
        
        tr[no] = mergeseg(tr[lc[no]],tr[rc[no]]);
        return no;
    }

    /* type */ qry(int no, int l, int r, int ll, int rr) {
        if(no == 0 or l > rr or r < ll) return /* neutral value */;
        if(l >= ll and r <= rr) return tr[no];
        int mid=(l+r)>>1;
        return mergeseg(qry(lc[no],l,mid,ll,rr),qry(rc[no],mid+1,r,ll,rr));
    }

    void update(int pos, /* type */ val) {
        upd(1,minv,maxv,pos,val);
    }

    /* type */ query(int l, int r) {
        return qry(1,minv,maxv,l,r);
    }
};
