#include "Animation.h"
#include "Mesh.h"
#include "Settings.h"
#include <cmath>

Animation::Animation(Mesh& mesh, Settings const& settings)
    : m_mesh(mesh)
    , m_amplitude(settings.GetAnimationAmplitude())
    , m_speed(settings.GetAnimationSpeed())
    , m_deltaTime(settings.GetAnimationDeltaTime())
    , m_time(0.f)
    , m_previousOffset(0.f)
{
}

void Animation::Update()
{
    m_time += m_deltaTime;
    float currentOffset = m_amplitude * std::cos(m_time * m_speed);
    float delta = currentOffset - m_previousOffset;
    m_previousOffset = currentOffset;
    
    m_mesh.Translate(0.f, delta, 0.f);
}

float Animation::GetCurrentOffset() const
{
    return m_previousOffset;
}

void Animation::SetAmplitude(float amplitude)
{
    m_amplitude = amplitude;
}

void Animation::SetSpeed(float speed)
{
    m_speed = speed;
}

void Animation::SetDeltaTime(float deltaTime)
{
    m_deltaTime = deltaTime;
}

float Animation::GetAmplitude() const
{
    return m_amplitude;
}

float Animation::GetSpeed() const
{
    return m_speed;
}

float Animation::GetDeltaTime() const
{
    return m_deltaTime;
}