/*
Standard Segment Tree
(Not tested yet)
minv,maxv -> Node 1 interval
start -> build(1,minv,maxv);
update position "pos" with "val" -> upd(1,minv,maxv,pos,val);
query on range L,R -> qry(1,minv,maxv,L,R);
*/

struct segtree {

	/* type */ tr[/* size */];

    void build(int no, int l, int r) {
        if(l == r) {
			tr[no] = /* inicial value */
		}
        int lc=2*no,rc=2*no+1,mid=(l+r)>>1;
        build(lc,l,mid);
        build(rc,mid+1,r);
		tr[no] = mergeseg(tr[lc],tr[rc]);
    }

    void upd(int no, int l, int r, int pos, /* type */ val) {
        if(l > pos or r < pos) return;
        if(l == r) {
            tr[no] = /* adds val to tr[no] */ 
            return;
        }
        int lc=2*no,rc=2*no+1,mid=(l+r)>>1;
        upd(lc,l,mid,pos,val);
        upd(rc,mid+1,r,pos,val);
        tr[no] = mergeseg(tr[lc],tr[rc]);
    }

    /* type */ qry(int no, int l, int r, int ll, int rr) {
        if(l > rr or r < ll) return /* neutral value */;
        if(l >= ll and r <= rr) return tr[no];
        int lc=2*no,rc=2*no+1,mid=(l+r)>>1;
        return mergeseg(qry(lc,l,mid,ll,rr),qry(rc,mid+1,r,ll,rr));
    }
};
