/* Copyright 2010-2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.

* This file is generated
*/
#include <aws/iotshadow/GetShadowResponse.h>

namespace Aws
{
    namespace Iotshadow
    {

        void GetShadowResponse::LoadFromObject(GetShadowResponse &val, const Aws::Crt::JsonView &doc)
        {
            (void)val;
            (void)doc;

            if (doc.ValueExists("state"))
            {
                val.State = doc.GetJsonObject("state");
            }

            if (doc.ValueExists("version"))
            {
                val.Version = doc.GetInteger("version");
            }

            if (doc.ValueExists("metadata"))
            {
                val.Metadata = doc.GetJsonObject("metadata");
            }

            if (doc.ValueExists("timestamp"))
            {
                val.Timestamp = doc.GetDouble("timestamp");
            }
        }

        void GetShadowResponse::SerializeToObject(Aws::Crt::JsonObject &object) const
        {
            (void)object;

            if (State)
            {
                Aws::Crt::JsonObject jsonObject;
                State->SerializeToObject(jsonObject);
                object.WithObject("state", std::move(jsonObject));
            }

            if (Version)
            {
                object.WithInteger("version", *Version);
            }

            if (Metadata)
            {
                Aws::Crt::JsonObject jsonObject;
                Metadata->SerializeToObject(jsonObject);
                object.WithObject("metadata", std::move(jsonObject));
            }

            if (Timestamp)
            {
                object.WithDouble("timestamp", Timestamp->SecondsWithMSPrecision());
            }
        }

        GetShadowResponse::GetShadowResponse(const Crt::JsonView &doc) { LoadFromObject(*this, doc); }

        GetShadowResponse &GetShadowResponse::operator=(const Crt::JsonView &doc)
        {
            *this = GetShadowResponse(doc);
            return *this;
        }

    } // namespace Iotshadow
} // namespace Aws
