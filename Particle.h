#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace mynamespace {

struct Particle {
	double m_x;
	double m_y;

private:
	double m_speed;
	double m_direction;

private:
	void init();

public:
	Particle();
	virtual ~Particle();
	void update(int interval);
};

} /* namespace mynamespace */

#endif /* PARTICLE_H_ */
