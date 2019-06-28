
#include "UniformImplementation_Legacy.h"

#include <glm/gtc/type_ptr.hpp>

#include <glbinding/gl/functions.h>
#include <glbinding/gl/boolean.h>

#include <globjects/Program.h>


using namespace gl;

#ifdef GLOBJECTS_USE_EIGEN
#include "EigenOpenGLSupport.h"
#endif

namespace globjects
{


void UniformImplementation_Legacy::set(const Program * program, const GLint location, const float & value) const
{
    program->use();
    glUniform1f(location, value);
}

void UniformImplementation_Legacy::set(const Program * program, const GLint location, const int & value) const
{
    program->use();
    glUniform1i(location, value);
}

void UniformImplementation_Legacy::set(const Program * program, const GLint location, const unsigned int & value) const
{
    program->use();
    glUniform1ui(location, value);
}

void UniformImplementation_Legacy::set(const Program * program, const GLint location, const bool & value) const
{
    program->use();
    glUniform1i(location, value ? 1 : 0);
}

void UniformImplementation_Legacy::set(const Program * program, const GLint location, const glm::vec2 & value) const
{
    program->use();
    glUniform2fv(location, 1, glm::value_ptr(value));
}

void UniformImplementation_Legacy::set(const Program * program, const GLint location, const glm::vec3 & value) const
{
    program->use();
    glUniform3fv(location, 1, glm::value_ptr(value));
}

void UniformImplementation_Legacy::set(const Program * program, const GLint location, const glm::vec4 & value) const
{
    program->use();
    glUniform4fv(location, 1, glm::value_ptr(value));
}

void UniformImplementation_Legacy::set(const Program * program, const GLint location, const glm::ivec2 & value) const
{
    program->use();
    glUniform2iv(location, 1, glm::value_ptr(value));
}

void UniformImplementation_Legacy::set(const Program * program, const GLint location, const glm::ivec3 & value) const
{
    program->use();
    glUniform3iv(location, 1, glm::value_ptr(value));
}

void UniformImplementation_Legacy::set(const Program * program, const GLint location, const glm::ivec4 & value) const
{
    program->use();
    glUniform4iv(location, 1, glm::value_ptr(value));
}

void UniformImplementation_Legacy::set(const Program * program, const GLint location, const glm::uvec2 & value) const
{
    program->use();
    glUniform2uiv(location, 1, glm::value_ptr(value));
}

void UniformImplementation_Legacy::set(const Program * program, const GLint location, const glm::uvec3 & value) const
{
    program->use();
    glUniform3uiv(location, 1, glm::value_ptr(value));
}

void UniformImplementation_Legacy::set(const Program * program, const GLint location, const glm::uvec4 & value) const
{
    program->use();
    glUniform4uiv(location, 1, glm::value_ptr(value));
}

void UniformImplementation_Legacy::set(const Program * program, const GLint location, const glm::mat2 & value) const
{
    program->use();
    glUniformMatrix2fv(location, 1, GL_FALSE, glm::value_ptr(value));
}

void UniformImplementation_Legacy::set(const Program * program, const GLint location, const glm::mat3 & value) const
{
    program->use();
    glUniformMatrix3fv(location, 1, GL_FALSE, glm::value_ptr(value));
}

void UniformImplementation_Legacy::set(const Program * program, const GLint location, const glm::mat4 & value) const
{
    program->use();
    glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(value));
}

void UniformImplementation_Legacy::set(const Program * program, const GLint location, const glm::mat2x3 & value) const
{
    program->use();
    glUniformMatrix2x3fv(location, 1, GL_FALSE, glm::value_ptr(value));
}

void UniformImplementation_Legacy::set(const Program * program, const GLint location, const glm::mat3x2 & value) const
{
    program->use();
    glUniformMatrix3x2fv(location, 1, GL_FALSE, glm::value_ptr(value));
}

void UniformImplementation_Legacy::set(const Program * program, const GLint location, const glm::mat2x4 & value) const
{
    program->use();
    glUniformMatrix2x4fv(location, 1, GL_FALSE, glm::value_ptr(value));
}

void UniformImplementation_Legacy::set(const Program * program, const GLint location, const glm::mat4x2 & value) const
{
    program->use();
    glUniformMatrix4x2fv(location, 1, GL_FALSE, glm::value_ptr(value));
}

void UniformImplementation_Legacy::set(const Program * program, const GLint location, const glm::mat3x4 & value) const
{
    program->use();
    glUniformMatrix3x4fv(location, 1, GL_FALSE, glm::value_ptr(value));
}

void UniformImplementation_Legacy::set(const Program * program, const GLint location, const glm::mat4x3 & value) const
{
    program->use();
    glUniformMatrix4x3fv(location, 1, GL_FALSE, glm::value_ptr(value));
}

void UniformImplementation_Legacy::set(const Program * program, const GLint location, const GLuint64 & value) const
{
    program->use();
    glUniformHandleui64ARB(location, value);
}

void UniformImplementation_Legacy::set(const Program * program, const GLint location, const std::vector<float> & value) const
{
    program->use();
    glUniform1fv(location, static_cast<GLint>(value.size()), value.data());
}

void UniformImplementation_Legacy::set(const Program * program, const GLint location, const std::vector<int> & value) const
{
    program->use();
    glUniform1iv(location, static_cast<GLint>(value.size()), value.data());
}

void UniformImplementation_Legacy::set(const Program * program, const GLint location, const std::vector<unsigned int> & value) const
{
    program->use();
    glUniform1uiv(location, static_cast<GLint>(value.size()), value.data());
}

void UniformImplementation_Legacy::set(const Program * program, GLint location, const std::vector<bool> & value) const
{
    std::vector<int> values(value.size());
    for (unsigned i = 0; i < values.size(); ++i)
    {
        values[i] = value[i] ? 1 : 0;
    }

    program->use();
    glUniform1iv(location, static_cast<GLint>(values.size()), values.data());
}

void UniformImplementation_Legacy::set(const Program * program, const GLint location, const std::vector<glm::vec2> & value) const
{
    program->use();
    glUniform2fv(location, static_cast<GLint>(value.size()), reinterpret_cast<const float*>(value.data()));
}

void UniformImplementation_Legacy::set(const Program * program, const GLint location, const std::vector<glm::vec3> & value) const
{
    program->use();
    glUniform3fv(location, static_cast<GLint>(value.size()), reinterpret_cast<const float*>(value.data()));
}

void UniformImplementation_Legacy::set(const Program * program, const GLint location, const std::vector<glm::vec4> & value) const
{
    program->use();
    glUniform4fv(location, static_cast<GLint>(value.size()), reinterpret_cast<const float*>(value.data()));
}

void UniformImplementation_Legacy::set(const Program * program, const GLint location, const std::vector<glm::ivec2> & value) const
{
    program->use();
    glUniform2iv(location, static_cast<GLint>(value.size()), reinterpret_cast<const int*>(value.data()));
}

void UniformImplementation_Legacy::set(const Program * program, const GLint location, const std::vector<glm::ivec3> & value) const
{
    program->use();
    glUniform3iv(location, static_cast<GLint>(value.size()), reinterpret_cast<const int*>(value.data()));
}

void UniformImplementation_Legacy::set(const Program * program, const GLint location, const std::vector<glm::ivec4> & value) const
{
    program->use();
    glUniform4iv(location, static_cast<GLint>(value.size()), reinterpret_cast<const int*>(value.data()));
}

void UniformImplementation_Legacy::set(const Program * program, const GLint location, const std::vector<glm::uvec2> & value) const
{
    program->use();
    glUniform2uiv(location, static_cast<GLint>(value.size()), reinterpret_cast<const unsigned*>(value.data()));
}

void UniformImplementation_Legacy::set(const Program * program, const GLint location, const std::vector<glm::uvec3> & value) const
{
    program->use();
    glUniform3uiv(location, static_cast<GLint>(value.size()), reinterpret_cast<const unsigned*>(value.data()));
}

void UniformImplementation_Legacy::set(const Program * program, const GLint location, const std::vector<glm::uvec4> & value) const
{
    program->use();
    glUniform4uiv(location, static_cast<GLint>(value.size()), reinterpret_cast<const unsigned*>(value.data()));
}

void UniformImplementation_Legacy::set(const Program * program, const GLint location, const std::vector<glm::mat2> & value) const
{
    program->use();
    glUniformMatrix2fv(location, static_cast<GLint>(value.size()), GL_FALSE, reinterpret_cast<const float*>(value.data()));
}

void UniformImplementation_Legacy::set(const Program * program, const GLint location, const std::vector<glm::mat3> & value) const
{
    program->use();
    glUniformMatrix3fv(location, static_cast<GLint>(value.size()), GL_FALSE, reinterpret_cast<const float*>(value.data()));
}

void UniformImplementation_Legacy::set(const Program * program, const GLint location, const std::vector<glm::mat4> & value) const
{
    program->use();
    glUniformMatrix4fv(location, static_cast<GLint>(value.size()), GL_FALSE, reinterpret_cast<const float*>(value.data()));
}

void UniformImplementation_Legacy::set(const Program * program, const GLint location, const std::vector<glm::mat2x3> & value) const
{
    program->use();
    glUniformMatrix2x3fv(location, static_cast<GLint>(value.size()), GL_FALSE, reinterpret_cast<const float*>(value.data()));
}

void UniformImplementation_Legacy::set(const Program * program, const GLint location, const std::vector<glm::mat3x2> & value) const
{
    program->use();
    glUniformMatrix3x2fv(location, static_cast<GLint>(value.size()), GL_FALSE, reinterpret_cast<const float*>(value.data()));
}

void UniformImplementation_Legacy::set(const Program * program, const GLint location, const std::vector<glm::mat2x4> & value) const
{
    program->use();
    glUniformMatrix2x4fv(location, static_cast<GLint>(value.size()), GL_FALSE, reinterpret_cast<const float*>(value.data()));
}

void UniformImplementation_Legacy::set(const Program * program, const GLint location, const std::vector<glm::mat4x2> & value) const
{
    program->use();
    glUniformMatrix4x2fv(location, static_cast<GLint>(value.size()), GL_FALSE, reinterpret_cast<const float*>(value.data()));
}

void UniformImplementation_Legacy::set(const Program * program, const GLint location, const std::vector<glm::mat3x4> & value) const
{
    program->use();
    glUniformMatrix3x4fv(location, static_cast<GLint>(value.size()), GL_FALSE, reinterpret_cast<const float*>(value.data()));
}

void UniformImplementation_Legacy::set(const Program * program, const GLint location, const std::vector<glm::mat4x3> & value) const
{
    program->use();
    glUniformMatrix4x3fv(location, static_cast<GLint>(value.size()), GL_FALSE, reinterpret_cast<const float*>(value.data()));
}

void UniformImplementation_Legacy::set(const Program* program, const GLint location, const std::vector<GLuint64> & value) const
{
    program->use();
    glUniformHandleui64vARB(location, static_cast<GLint>(value.size()), value.data());
}

#ifdef GLOBJECTS_USE_EIGEN

template<typename T>
inline void eigenSet(const Program *program, gl::GLint location, const T& value) {
    program->use();
    Eigen::glUniform(location, value);
}

template<typename T>
inline void eigenSet(const Program *program, gl::GLint location, const std::vector<T>& value) {
    program->use();
    // TODO: implement vector variants of Eigen::glUniform
    // Eigen::glUniform(location, value);
}

void UniformImplementation_Legacy::set(const Program *program, gl::GLint location, const Eigen::Vector2f &value) const { eigenSet(program, location, value); }
void UniformImplementation_Legacy::set(const Program *program, gl::GLint location, const Eigen::Vector3f &value) const { eigenSet(program, location, value); }
void UniformImplementation_Legacy::set(const Program *program, gl::GLint location, const Eigen::Vector4f &value) const { eigenSet(program, location, value); }

void UniformImplementation_Legacy::set(const Program *program, gl::GLint location, const Eigen::Vector2i &value) const { eigenSet(program, location, value); }
void UniformImplementation_Legacy::set(const Program *program, gl::GLint location, const Eigen::Vector3i &value) const { eigenSet(program, location, value); }
void UniformImplementation_Legacy::set(const Program *program, gl::GLint location, const Eigen::Vector4i &value) const { eigenSet(program, location, value); }

void UniformImplementation_Legacy::set(const Program *program, gl::GLint location, const Eigen::Matrix<uint, 2, 1> &value) const { eigenSet(program, location, value); }
void UniformImplementation_Legacy::set(const Program *program, gl::GLint location, const Eigen::Matrix<uint, 3, 1> &value) const { eigenSet(program, location, value); }
void UniformImplementation_Legacy::set(const Program *program, gl::GLint location, const Eigen::Matrix<uint, 4, 1> &value) const { eigenSet(program, location, value); }

void UniformImplementation_Legacy::set(const Program *program, gl::GLint location, const Eigen::Matrix2f & value) const { eigenSet(program, location, value); }
void UniformImplementation_Legacy::set(const Program *program, gl::GLint location, const Eigen::Matrix3f & value) const { eigenSet(program, location, value); }
void UniformImplementation_Legacy::set(const Program *program, gl::GLint location, const Eigen::Matrix4f & value) const { eigenSet(program, location, value); }

void UniformImplementation_Legacy::set(const Program *program, gl::GLint location, const Eigen::Matrix<float, 2, 3> & value) const { eigenSet(program, location, value); }
void UniformImplementation_Legacy::set(const Program *program, gl::GLint location, const Eigen::Matrix<float, 3, 2> & value) const { eigenSet(program, location, value); }
void UniformImplementation_Legacy::set(const Program *program, gl::GLint location, const Eigen::Matrix<float, 2, 4> & value) const { eigenSet(program, location, value); }
void UniformImplementation_Legacy::set(const Program *program, gl::GLint location, const Eigen::Matrix<float, 4, 2> & value) const { eigenSet(program, location, value); }
void UniformImplementation_Legacy::set(const Program *program, gl::GLint location, const Eigen::Matrix<float, 3, 4> & value) const { eigenSet(program, location, value); }
void UniformImplementation_Legacy::set(const Program *program, gl::GLint location, const Eigen::Matrix<float, 4, 3> & value) const { eigenSet(program, location, value); }

void UniformImplementation_Legacy::set(const Program *program, gl::GLint location, const std::vector<Eigen::Vector2f> & value) const { eigenSet(program, location, value); }
void UniformImplementation_Legacy::set(const Program *program, gl::GLint location, const std::vector<Eigen::Vector3f> & value) const { eigenSet(program, location, value); }
void UniformImplementation_Legacy::set(const Program *program, gl::GLint location, const std::vector<Eigen::Vector4f> & value) const { eigenSet(program, location, value); }

void UniformImplementation_Legacy::set(const Program *program, gl::GLint location, const std::vector<Eigen::Vector2i> & value) const { eigenSet(program, location, value); }
void UniformImplementation_Legacy::set(const Program *program, gl::GLint location, const std::vector<Eigen::Vector3i> & value) const { eigenSet(program, location, value); }
void UniformImplementation_Legacy::set(const Program *program, gl::GLint location, const std::vector<Eigen::Vector4i> & value) const { eigenSet(program, location, value); }


#endif


} // namespace globjects
