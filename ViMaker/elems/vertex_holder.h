#pragma once
#include "../ViMaker.h"

namespace nelems
{
  class VertexHolder
  {

  public:
    VertexHolder() : mPos(), mNormal() {}
    VertexHolder(const glm::vec3& pos, const glm::vec3& normal)
      : mPos(pos), mNormal(normal)
    {
    }
    ~VertexHolder() = default;
    glm::vec3 mPos;

    glm::vec3 mNormal;

  };
}

