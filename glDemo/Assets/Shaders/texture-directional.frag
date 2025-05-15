#version 450 core

// Diffuse texture - directional light

// Texture sampler (for diffuse surface colour)
layout(binding = 0) uniform sampler2D texture;

// Directional light model
uniform vec3 DIR1Dir;
uniform vec3 DIR1Col;
uniform vec3 DIR1Amb;

// Directional light model
uniform vec3 DIR2Dir;
uniform vec3 DIR2Col;
uniform vec3 DIR2Amb;


in SimplePacket {
	
	vec3 surfaceWorldPos;
	vec3 surfaceNormal;
	vec2 texCoord;

} inputFragment;


layout (location=0) out vec4 fragColour;

void main(void) {

	// calculate lambertian (l)
    vec3 N = normalize(inputFragment.surfaceNormal);  
    float l1 = max(dot(N, normalize(DIR1Dir)), 0.0);  
    float l2 = max(dot(N, normalize(DIR2Dir)), 0.0);  

    // Calculate diffuse brightness / color for fragment  
    vec4 surfaceColour = texture(texture, inputFragment.texCoord);  
    vec3 diffuseColour1 = surfaceColour.rgb * DIR1Col * l1;  
    vec3 diffuseColour2 = surfaceColour.rgb * DIR2Col * l2;  

    fragColour = vec4(DIR1Amb, 1.0) + vec4(diffuseColour1, 0.0);
    fragColour += vec4(DIR2Amb, 1.0) + vec4(diffuseColour2, 0.0);
	//fragColour = vec4(vec3(l, l, l), 1.0);
}
