#pragma once

class Mesh;
class Settings;

class Animation
{
public:
    Animation(Mesh& mesh, Settings const& settings);
    
    void Update();
    
    void SetAmplitude(float amplitude);
    void SetSpeed(float speed);
    void SetDeltaTime(float deltaTime);

    float GetAmplitude() const;
    float GetSpeed() const;
    float GetDeltaTime() const;
    float GetCurrentOffset() const;

private:
    Mesh& m_mesh;
    float m_amplitude;
    float m_speed;
    float m_deltaTime;
    float m_time;
    float m_previousOffset;
};