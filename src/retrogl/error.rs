use gl;
use gl::types::GLenum;

use retrogl::shader::ShaderType;

/// OpenGL errors
#[derive(Copy, Clone, PartialEq, Eq, Debug)]
pub enum Error {
    /// Error codes returned by glGetError
    InvalidEnum,
    InvalidValue,
    InvalidOperation,
    InvalidFramebufferOperatior,
    OutOfMemory,
    /// In case we encounter an unknown OpenGL error code
    Unknown(GLenum),
    /// When shader compilation fails
    BadShader(ShaderType),
    /// When program linking fails
    BadProgram,
    /// When using a bad/unknown uniform
    BadUniform,
}

pub fn get_error() -> Result<(), Error> {
    let e =
    match unsafe { gl::GetError() } {
        gl::NO_ERROR => Ok(()),
        gl::INVALID_ENUM => Err(Error::InvalidEnum),
        gl::INVALID_VALUE => Err(Error::InvalidValue),
        gl::INVALID_OPERATION => Err(Error::InvalidOperation),
        gl::INVALID_FRAMEBUFFER_OPERATION =>
            Err(Error::InvalidFramebufferOperatior),
        gl::OUT_OF_MEMORY => Err(Error::OutOfMemory),
        n => Err(Error::Unknown(n)),
    };

    if let Err(e) = e {
        println!("GL error {:?}", e);
    }

    e
}

/// Return `Ok(v)` if no OpenGL error flag is active
pub fn error_or<T>(v: T) -> Result<T, Error> {
    get_error().map(|_| v)
}
