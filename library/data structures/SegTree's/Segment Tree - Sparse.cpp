/*
Sparse Segment Tree
(Não terminei ainda - parei no upd)
minv,maxv -> Node 1 interval
start -> build(1,minv,maxv);
update position "pos" with "val" -> upd(1,minv,maxv,pos,val);
query on range L,R -> qry(1,minv,maxv,L,R);
*/

struct segtree {

	/* type */ tr[/* size */];
	int lc[/* size */], rc[/* size */];
	int cntnode = 0;

	/* type */ mergeseg(/* type */ valL, /* type */ valR) {
		
		/* return merge of valL and valR */
	}

    int upd(int no, int l, int r, int pos, /* type */ val) {
        if(l > pos or r < pos) return no;

		if(no == 0) {
			no = ++cntno;
			lc[no] = 0;
			rc[no] = 0;
			tr[no] = /* neutral value */;
		}
		
        if(l == r) {
            tr[no] = /* adds val to tr[no] */;
            return no;
        }
        int mid=(l+r)>>1;
		lc[no] = upd(lc[no],l,mid,pos,val);
		rc[no] = upd(rc[no],mid+1,r,pos,val);
        tr[no] = mergeseg(tr[lc],tr[rc]);
		return no;
    }

    /* type */ qry(int no, int l, int r, int ll, int rr) {
        if(l > rr or r < ll) return /* neutral value */;
        if(l >= ll and r <= rr) return tr[no];
        int lc=2*no,rc=2*no+1,mid=(l+r)>>1;
        return mergeseg(qry(lc,l,mid,ll,rr),qry(rc,mid+1,r,ll,rr));
    }
};
