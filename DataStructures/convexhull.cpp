// Implementation of Andrew's monotone chain 2D convex hull algorithm.
// Asymptotic complexity: O(n log n).
// Practical performance: 0.5-1.0 seconds for n=1000000 on a 1GHz machine.
#include <algorithm>
#include <vector>
using namespace std;

typedef double coord_t;         // coordinate type
typedef double coord2_t;  // must be big enough to hold 2*max(|coordinate|)^2

struct point {
	double x, y;
	point(){}
	point(double a,double b){ 
		x=a;
		y=b; 
	}
	bool operator <(const point &p) const {
		return x < p.x || (x == p.x && y < p.y);
	}
};

// 2D cross product of OA and OB vectors, i.e. z-component of their 3D cross product.
// Returns a positive value, if OAB makes a counter-clockwise turn,
// negative for clockwise turn, and zero if the points are collinear.
coord2_t cross(const point &O, const point &A, const point &B)
{
	return (long)(A.x - O.x) * (B.y - O.y) - (long)(A.y - O.y) * (B.x - O.x);
}

// Returns a list of points on the convex hull in counter-clockwise order.
// Note: the last point in the returned list is the same as the first one.
vector<point> convex_hull(vector<point> P)
{
	int n = P.size(), k = 0;
	vector<point> H(2*n);

	// Sort points lexicographically
	sort(P.begin(), P.end());

	// Build lower hull
	for (int i = 0; i < n; ++i) {
		while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
		H[k++] = P[i];
	}

	// Build upper hull
	for (int i = n-2, t = k+1; i >= 0; i--) {
		while (k >= t && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
		H[k++] = P[i];
	}

	H.resize(k);
	return H;
}

double sign (point p1, point p2, point p3)
{
    return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
}

bool PointInTriangle (point pt, point v1, point v2, point v3)
{
    bool b1, b2, b3;

    b1 = sign(pt, v1, v2) < 0.0f;
    b2 = sign(pt, v2, v3) < 0.0f;
    b3 = sign(pt, v3, v1) < 0.0f;

    return ((b1 == b2) && (b2 == b3));
}

double CalcTriArea(point *v1, point *v2, point *v3)
{
  double det = 0.0f;
  det = ((v1->x - v3->x) * (v2->y - v3->y)) - ((v2->x - v3->x) * (v1->y - v3->y));
  return (det / 2.0f);
}

int  main()
{
	std::vector<point> v;
	v.push_back(point(1.1,2.0));
	v.push_back(point(1.7,2.2));
	v.push_back(point(4.1,3.0));
	v.push_back(point(2.1,2.0));
	v.push_back(point(0.1,3.0));
	v.push_back(point(1.1,1.0));
	v.push_back(point(6.1,6.0));
	v.push_back(point(3.1,4.3));
	std::vector<point> res = convex_hull(v);
	for(point cur : res){
		printf("{%lf,%lf}\n",cur.x,cur.y );
	}
	if(PointInTriangle(point(1.1,2.0), point(0.1,3.0),point(6.1,6.0),point(1.1,1.0)))
		printf("point is inside the triangle\n");

	return 0;
}