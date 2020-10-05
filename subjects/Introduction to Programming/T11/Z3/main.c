#include <stdio.h>
#include <math.h>

/* pravougaonik */
/* Definicija tacke i kruznice */
struct Tacka {
	float x,y;
};

struct Pravougaonik {
	struct Tacka dole_lijevo;
	struct Tacka gore_desno;
};

/* functions  */
float obim_pravougaonika(struct Pravougaonik p) {
	return (2*(fabs(p.dole_lijevo.x - p.gore_desno.x) + fabs(p.dole_lijevo.y - p.gore_desno.y)));
}

float povrsina_pravougaonika(struct Pravougaonik p) {
	return ((fabs(p.dole_lijevo.x - p.gore_desno.x)*fabs(p.dole_lijevo.y - p.gore_desno.y)));
}

int tacka_u_pravougaoniku(struct Tacka point, struct Pravougaonik p) {
	/* check */
	if(!((p.gore_desno.x >= point.x && p.dole_lijevo.x <= point.x) && 
	(p.dole_lijevo.y <= point.y && p.gore_desno.y >= point.y))) 
		return 0;
	return 1;
}



int main() {
	/* initial */
	
	
	
	return 0;
}
