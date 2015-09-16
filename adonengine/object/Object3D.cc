#include "Object3D.h"
#include "GL/glew.h"
#include "GL/gl.h"
#include "Camera.h"

Object3D::Object3D()
{

}

Object3D::Object3D(Instance ins)
{
	this->graphicdata = ins;
	this->globaltransform = Mat4::InitIdentityMat4F();
	this->transform = Mat4::InitIdentityMat4F();
}

Object3D::Object3D(Instance ins, Matrix4F _transform)
{
	this->graphicdata = ins;
	this->transform = _transform;
}

void Object3D::ChildOf(Object3D &other)
{
	other.createConnection(this);
}

void Object3D::createConnection(Object3D* other)
{
	this->children.push_back(other);
}

bool Object3D::hasChildren()
{
	if (this->children.size() == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void Object3D::Update(Matrix4F _transform)
{
	this->globaltransform = _transform * this->transform;	
	if (this->hasChildren())
	{
		for (int i = 0; i < this->children.size(); i++)
		{
			this->children[i]->Update(this->globaltransform);
		}
	}
}

Matrix4F Object3D::GetTransform()
{
	return this->transform;
}

void Object3D::SetLocalMatrix(Matrix4F _matrix)
{
	this->transform = _matrix;
}

Matrix4F* Object3D::GetGlobalAddress()
{ 
	return &this->globaltransform;
}


void Object3D::Render(Camera& acc)
{
	//Change!
	if (!this->graphicdata.isInitilized())
	{
	  
	}
	else
	{
	  ///CHECKS FOR BOUNDING SPHERE
	  if(this->graphicdata.GetBounds()->Def()==BOUNDINGSPHERE){
	    float radius = this->graphicdata.GetBounds()->Radius();
	    Vector3f center = this->graphicdata.GetBounds()->Center();
	    
	    float sx = Vector3f(this->globaltransform[0][0], this->globaltransform[0][1], this->globaltransform[0][2]).lenght();
	    float sy = Vector3f(this->globaltransform[1][0], this->globaltransform[1][1], this->globaltransform[1][2]).lenght();
	    float sz = Vector3f(this->globaltransform[2][0], this->globaltransform[2][1], this->globaltransform[2][2]).lenght();
	    if (acc.PointInFrustrum(Vector3f(this->globaltransform[0][3], this->globaltransform[1][3], this->globaltransform[2][3]), radius*sx))
	    {
	      if (this->graphicdata.GetRenderInfo().CULL_FACE == DISABLE_CULL_FACE)
	      {
		glDisable(GL_CULL_FACE);
	      }
	      GLfloat lightpos[3] = { 100, 100, 10 };
	      Matrix4F ident = this->globaltransform;
	      Matrix4F MVP = acc.GetPerspective() * acc.GetViewMatrix() * this->globaltransform;
	      glUseProgram(this->graphicdata.GetProgram());
	      glBindVertexArray(this->graphicdata.GetVAO());
	      glUniformMatrix4fv(this->graphicdata.GetUniform("MVP"), 1, GL_TRUE, MVP);
	      glUniformMatrix4fv(this->graphicdata.GetUniform("v"), 1, GL_TRUE, acc.GetViewMatrix());
	      glUniformMatrix4fv(this->graphicdata.GetUniform("m"), 1, GL_TRUE, ident);
	      glUniform3fv(this->graphicdata.GetUniform("LightPosition_worldspace"), 1, lightpos);
 	      for (int i = 0; i < this->graphicdata.MaterialCount(); i++)
 	      {
		glUniform3fv(this->graphicdata.GetUniform(this->graphicdata.GetMaterial(i).uniformname), 1, this->graphicdata.GetMaterial(i).material.data);
	      }
	      if (this->graphicdata.GetRenderInfo().textinfo == TEXTURE_ON)
	      {
		glBindTexture(GL_TEXTURE_2D, this->textureid);
	      }
	      if (this->graphicdata.GetRenderInfo().drawinfo == DRAWELEMENTS)
	      {
		glDrawElements(GL_TRIANGLES, this->graphicdata.GetCount(), GL_UNSIGNED_SHORT, (void*)0);
	      }
	      else
	      {
		glDrawArrays(GL_TRIANGLES, 0, this->graphicdata.GetCount());
	      }
	      glBindVertexArray(0);
	      if (this->graphicdata.GetRenderInfo().CULL_FACE == DISABLE_CULL_FACE)
	      {
		glEnable(GL_CULL_FACE);
	      }
	    }
	  }
	  else if(this->graphicdata.GetBounds()->Def()==BOUNDINGBOX){
	    if (this->graphicdata.GetRenderInfo().CULL_FACE == DISABLE_CULL_FACE)
	    {
	      glDisable(GL_CULL_FACE);
	    }
	    GLfloat lightpos[3] = { 100, 100, 10 };
	    Matrix4F ident = this->globaltransform;
	    Matrix4F MVP = acc.GetPerspective() * acc.GetViewMatrix() * this->globaltransform;
	    glUseProgram(this->graphicdata.GetProgram());
	    glBindVertexArray(this->graphicdata.GetVAO());
 	    glUniformMatrix4fv(this->graphicdata.GetUniform("MVP"), 1, GL_TRUE, MVP);
 	    glUniformMatrix4fv(this->graphicdata.GetUniform("v"), 1, GL_TRUE, acc.GetViewMatrix());
	    glUniformMatrix4fv(this->graphicdata.GetUniform("m"), 1, GL_TRUE, ident);
 	    glUniform3fv(this->graphicdata.GetUniform("LightPosition_worldspace"), 1, lightpos);
	    for (int i = 0; i < this->graphicdata.MaterialCount(); i++)
 	    {
 	      glUniform3fv(this->graphicdata.GetUniform(this->graphicdata.GetMaterial(i).uniformname), 1, this->graphicdata.GetMaterial(i).material.data);
 	    }
	    if (this->graphicdata.GetRenderInfo().textinfo == TEXTURE_ON)
	    {
	      glBindTexture(GL_TEXTURE_2D, this->textureid);
	    }

	    if (this->graphicdata.GetRenderInfo().drawinfo == DRAWELEMENTS)
	    {
	      glDrawElements(GL_TRIANGLES, this->graphicdata.GetCount(), GL_UNSIGNED_SHORT, (void*)0);
	    }
	    else
	    {
	      glDrawArrays(GL_TRIANGLES, 0, this->graphicdata.GetCount());
	    }
	    glBindVertexArray(0);
	    if (this->graphicdata.GetRenderInfo().CULL_FACE == DISABLE_CULL_FACE)
	    {
	      glEnable(GL_CULL_FACE);
	    }
	  }
	}
	if (this->hasChildren())
	{
		for (int i = 0; i < this->children.size(); i++)
		{
			this->children[i]->Render(acc);
		}
	}
}


void Object3D::SetTextureID(int textureid)
{
	this->textureid = textureid;
}

int Object3D::GetTextureID()
{
	return this->textureid;
}

void Object3D::Initilize(int ins)
{
  this->instance_id = ins;
}


void Object3D::AddMaterial(string name, Vector3f data)
{
	this->graphicdata.AddMaterial(name, data);
}

Material& Object3D::GetMaterial(string name)
{
  return this->graphicdata.GetMaterial(name);
}


Instance& Object3D::GetInstance()
{
	return this->graphicdata;
}